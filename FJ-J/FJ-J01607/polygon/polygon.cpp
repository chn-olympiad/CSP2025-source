#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int mod=998244353;
int n,a[5010],ans;
void dfs(int k,int num,int ma,int sum){
	if(k==n+1){
		if(num>=3&&sum>2*ma){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(k+1,num,ma,sum);
	dfs(k+1,num+1,max(ma,a[k]),sum+a[k]);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	//cin>>num;
	while(num--)solve();
	return 0;
}
