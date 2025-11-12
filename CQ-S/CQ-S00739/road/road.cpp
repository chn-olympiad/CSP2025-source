#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+20+1e5;
const int M=1e4+5;
int f[N],xl[M][M],ans,jz[100];
int n,m,k;
struct Edge{
	int u,v,w;
}e[N];
bool cmp(Edge a,Edge b){
	return a.w<b.w;	
}
int find_fa(int x){
	if(x!=f[x]) f[x]=find_fa(f[x]);
	return f[x];
}
int pd(){
	for(int i=1;i<=m+k*n;i++){
		int dx=find_fa(e[i].u);
		int dy=find_fa(e[i].v);
		if(dx!=dy) return 1;
	}
	return 0;
}
int kruskal(){
	sort(e+1,e+m+k+1,cmp);
	for(int i=1;i<=m+k*n;i++){
		f[i]=i;	
	}
	int num=0;
	for(int i=1;i<=m+k*n;i++){
		if(!pd()) break;
		int dx=find_fa(e[i].u);
		int dy=find_fa(e[i].v);
		if(dx!=dy){
			f[dx]=dy;
			ans+=e[i].w;//cout<<ans<<" ";
			xl[e[i].u][e[i].v]=e[i].w;
			if(e[i].u<=n&&e[i].v<=n) num++;
		//	cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(xl,0,sizeof(xl));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	int js=m,jk=n,kk=k;
	while(kk--){
		jk++;
		cin>>jz[jk];
		for(int i=1;i<=n;i++){
			js++;
			int w;
			cin>>w;
			e[js].u=jk;
			e[js].v=i;
			e[js].w=w;
		}
	}
	kruskal();
	//cout<<n<<m<<k;
//	for(int i=1;i<=n+k-1;i++){
//		for(int j=1;j<=n+k-1;j++){
//			cout<<xl[i][j]<<" ";
//		}
//	}
	for(int i=n+1;i<=jk;i++){
		int pdx=0,jzx=0;
		for(int j=1;j<=n;j++){
			if(xl[i][j]||xl[j][i]){
				pdx++;
				jzx=max(xl[i][j],xl[j][i]);
//				cout<<"ppp";
//				cout<<i<<" "<<j;
			}
		}
		if(pdx==1){
			ans-=jzx;//cout<<"jzx"<<jzx;
		}
		else if(pdx>1) ans+=jz[i];
	}
    cout<<ans;
	return 0;
}

