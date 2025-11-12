#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 998244353;
ll n,m,a[505],flag,c[505],ans;
bool vis[505];
char s;
void dfs(int x,int sum,int sum2){
	if(x==n+1){
		if(sum2>=m) ans = (ans+1)%N;
		return ; 
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i] = 1;
			if(sum>=c[i]||a[x]==0) dfs(x+1,sum+1,sum2);
			else dfs(x+1,sum,sum2+1);
			vis[i] = 0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s;
		a[i] = s-'0';
		if(a[i]==0) flag=1;
	}	
	for(int i=1;i<=n;i++) cin>>c[i];
	if(!flag){
		ans = 1;
		for(int i=2;i<=n;i++)
			ans *= i;
		cout << ans;
		return 0;
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
