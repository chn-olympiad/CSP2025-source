#include<bits/stdc++.h>
using namespace std;
#define mxn 10100
#define mxm 1100010
#define ll long long
#define pii pair<int,int>
//#define X first
//#define Y second
int n,m,k,a[20][mxn],c[20];
pair<ll,pii> e[mxm],e2[mxm];
int f[mxn];
ll cnt=0;
int fnd(int x){
	if(f[x]==x)return x;
	return f[x]=fnd(f[x]);
}
void sol1(){
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+m+1);
	ll ans=0;cnt=0;
	for(int i=1;i<=m;i++){
		ll w=e[i].first;
		int u=e[i].second.first,v=e[i].second.second;
		int fu=fnd(u),fv=fnd(v);
		if(fu==fv)continue;
		cnt++,ans+=w,f[fu]=fv;
		if(cnt==n-1)break;
	}
	cout<<ans<<'\n';
}
int vis[6];ll Ans=1e17;
void dfs(int nw){
	if(nw>k){
		ll ans=0;cnt=0;
		for(int i=1;i<=m;i++)e2[i]=e[i];
		for(int i=1;i<=k;i++){
			if(!vis[i])continue;
			ans+=c[i],cnt++;
			for(int j=1,num=m+(cnt-1)*n+1;j<=n;j++,num++)
				e2[num]={a[i][j],{n+cnt,j}};
		}
		for(int i=1;i<=n+cnt;i++)f[i]=i;
		sort(e2+1,e2+m+cnt*n+1);
		int cnt2=0;
		for(int i=1;i<=m+cnt*n;i++){
			ll w=e2[i].first;
			int u=e2[i].second.first,v=e2[i].second.second;
			int fu=fnd(u),fv=fnd(v);
			if(fu==fv)continue;
			cnt2++,ans+=w,f[fu]=fv;
			if(cnt2==n+cnt-1)break;
		}
		Ans=min(Ans,ans);
		return;	
	}
	dfs(nw+1),vis[nw]=1;
	dfs(nw+1),vis[nw]=0;
}
void sol2(){
	dfs(1),cout<<Ans<<'\n';
}
bool checkA(){
	for(int i=1;i<=k;i++)if(c[i])return 0;
	return 1;
}
void sol3(){
	cnt=0;ll ans=0;
	for(int i=1;i<=k;i++){
		cnt++;
		for(int j=1,num=m+(cnt-1)*n+1;j<=n;j++,num++)
			e[num]={a[i][j],{n+cnt,j}};
	}
	for(int i=1;i<=n+cnt;i++)f[i]=i;
	sort(e+1,e+m+cnt*n+1);
	int cnt2=0;
	for(int i=1;i<=m+cnt*n;i++){
		ll w=e[i].first;
		int u=e[i].second.first,v=e[i].second.second;
		int fu=fnd(u),fv=fnd(v);
		if(fu==fv)continue;
		cnt2++,ans+=w,f[fu]=fv;
		if(cnt2==n+cnt-1){
			break;
//			cout<<i<<'\n';
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={w,{u,v}};
	}
	if(!k){sol1();return 0;} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k<=5&&m<=100000){sol2();return 0;}
	if(checkA()){sol3();return 0;}
	return 0;
}
