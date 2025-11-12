#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f,mod=1e9+7;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int n,m,k,m2,chk;
int f[N],c[N],cp[15][N],ans;
int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
struct Edge{
	int u,v,w;
	bool operator <(const Edge&x)const
		{return w<x.w;}
}e[N],e2[N];
int kruskal(){
	int ans=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1,j=1;i<=m||j<=m2;){
		int u,v,w;
		if(i>m||j<=m2&&e2[j].w<e[i].w) u=e2[j].u,v=e2[j].v,w=e2[j].w,++j;
		else u=e[i].u,v=e[i].v,w=e[i].w,++i; 
		int tu=u,tv=v;
		if((u=find(u))==(v=find(v))) continue;
		//cout<<tu<<" "<<tv<<" "<<w<<"\n";
		f[u]=v; ans+=w;
	}
	return ans;
}
void CaseA(){
	for(int j=0;j<k;j++)
		for(int i=1;i<=n;i++)
			e[++m]={n+j+1,i,cp[j][i]};
	sort(e+1,e+m+1);
	cout<<kruskal();
}
void mian(){
	sort(e+1,e+m+1);
	ans=kruskal();
	for(int i=1;i<(1ll<<k);i++){
		int cnt=0; m2=0;
		for(int j=0;j<k;j++){
			if(!((i>>j)&1)) continue;
			cnt+=c[j];
			for(int p=1;p<=n;p++)
				e2[++m2]={j+n+1,p,cp[j][p]};
		}
		sort(e2+1,e2+m2+1); 
		cnt+=kruskal();
		//cout<<cnt<<"\n";
		ans=min(ans,cnt);
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int j=0;j<k;j++){
		cin>>c[j]; chk=max(chk,c[j]);
		for(int i=1;i<=n;i++) cin>>cp[j][i];
	}
	if(!chk) CaseA();
	else mian();
	return 0;
}

