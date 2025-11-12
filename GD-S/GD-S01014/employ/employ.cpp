#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
string s;
int n,m,c[1001],p[1001],q[1001];
int fact(int x){
	int ans=1;
	for(int i=2;i<=x;i++)(ans*=i)%=mod;
	return ans;
}
int vis[1001],ans=0;
void dfs(int x,int suc,int fil){
	if(x>n)return;
	if(n-fil<m)return;
	if(suc>=m){
		(ans+=fact(n-x))%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,suc+(s[x]=='1'&&fil<c[i]),fil+(s[x]=='0'||fil>=c[i]));
			vis[i]=0;
		}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
