#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+10;
int a[N],b[N];
int n,ans;
bool mark[5010];
long long MOD = 998244353;
void dfs(int step,int xd,int dq){
	if(step == xd+1){
		int maxn = -1;
		int sum = 0;
		for(int i = 1;i <= xd;i++){
			//cout << b[i]<<" ";
			maxn = max(maxn,b[i]);
			sum += b[i];
		}
		//cout << endl;
		//cout << maxn <<" "<< sum<<endl;
		if(sum > 2 * maxn){
			ans += 1;
			ans = ans % MOD;
		}
		//cout << (sum > 2 * maxn)<<" "<<ans<<endl;
		return ;
	}
	for(int i = dq;i <= n;i++){
		if(mark[a[i]] == 0){
			mark[a[i]] = 1;
			b[step] = a[i];
			dfs(step + 1,xd,i+1);
			mark[a[i]] = 0;
		}
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int flag = 1;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mark[a[i]] = 0;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] != 1){
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		cout << ((n-4+1+1)*(n-4+1))/2;
		return 0;
	}
	for(int dbx = 3;dbx <= n;dbx++){
		dfs(1,dbx,1);
	}
	cout << ans;
	return 0;
} 
