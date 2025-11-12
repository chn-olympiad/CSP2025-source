#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m,a[505],b[505],c[505],ans;
bool vis[505];
string s; 
void dfs(int t,int sum1,int sum2){
	if(sum1+b[t]<m)return;
	if(sum1>=m)ans=(ans+1)%MOD;
	if(t>n)return;
	for(int i=1;i<=n;i++){
		if(s[t]=='1'&&!vis[i]&&a[i]>sum2){
//			cout<<t<<' '<<i<<' '<<sum1+1<<' '<<sum2<<' '<<"A"<<'\n';
			vis[i]=1;
			dfs(t+1,sum1+1,sum2);
			vis[i]=0;
		}
		if(!vis[i]&&(a[i]<=sum2||s[t]=='0')){
//			cout<<t<<' '<<i<<' '<<sum1<<' '<<sum2+1<<' '<<"B"<<'\n';
			vis[i]=1;
			dfs(t+1,sum1,sum2+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)b[i]=b[i+1]+s[i]-'0';
	for(int i=1;i<=n;i++)c[i]=c[i-1]+s[i]-'0';
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
