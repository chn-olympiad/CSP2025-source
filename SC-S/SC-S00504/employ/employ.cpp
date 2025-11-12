#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510;
const ll MOD=998244353;
int n,m,cnt=0,t0=0;
string s;
bool f[N],vis[N];
int a[N],d[N];
ll jc[N];
ll ans=0;
void dfs(int step,int sum,int unu){
	if(sum>=m){
		ans=(ans+jc[n-step+1])%MOD;
		return;
	}
	if(step>n) return;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		int t=0;
		if(a[i]>unu&&f[step]) t=1;
		dfs(step+1,sum+t,unu+1-t);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	jc[0]=1;
	for(int i=1;i<=n+5;i++) jc[i]=(jc[i-1]*(ll)i)%MOD;
	cin>>s;
	bool flag=1;
	for(int i=0;i<n;i++) f[i+1]=s[i]-'0',flag&=f[i+1];
	d[0]=0;
	for(int i=1;i<=n;i++) if(!f[i]) d[++cnt]=i;
	while(cnt<=n+1) d[++cnt]=n+5;
	for(int i=1;i<=n;i++) cin>>a[i],flag=(a[i]>0)?flag:0;
	if(m==n){
		if(flag) cout<<jc[n]<<"\n";
		else cout<<"0\n";
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}