#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
inline void read(int &a){
	int k=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+(ch-'0');ch=getchar();}
	a=f*k;
}
struct edge{
	int from,end,w,id;
}e[M];
inline bool cmp(edge x,edge y){
	return 	x.w<y.w;
}
int n,m,k,c[N],cnt,t[N];
int f[N],cn,ans;
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=n+m;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		read(e[++cnt].from),read(e[cnt].end),read(e[cnt].w);
		e[cnt].id=cnt;
	}
	int flg=0;
	for(int i=1;i<=k;i++){
		read(c[i]);
		if(c[i]!=0) flg=1;
		for(int j=1;j<=n;j++)
			read(t[j]);
		for(int j=1;j<=n;j++){
			for(int jj=j+1;jj<=n;jj++){
				if(j==jj) continue;
				e[++cnt].from=j;
				e[cnt].end=jj;
				e[cnt].id=cnt;
				e[cnt].w=t[j]+t[jj]; 
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<e[i].from<<' '<<e[i].end<<' '<<e[i].w;
		cout<<"\n";
	}
	if(!flg){
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int u=e[i].from,v=e[i].end,id=e[i].id;
			if(find(u)==find(v)) continue;
			int fu=find(u),fv=find(v);
			f[v]=fu;
			cn++;ans+=e[i].w;
			if(cn==n-1) break;
		}
		cout<<ans;		
	}

	return 0;
} 

