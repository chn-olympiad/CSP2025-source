#include<bits/stdc++.h>
using namespace std;
int fa[10005];
struct edge{
	int u,v,w;
};
edge e[20000005];
int tj[20][10005];
inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
int cnt=0,f[20];
int find(int a){
	if(fa[a]!=a){
		return fa[a]=find(fa[a]);
	}
	return a;
}
int read(){
	int l=0;
	char k=getchar();
	while(k>='0'&&k<='9'){
		l=l*10+(k-'0');
		k=getchar();
	}
	return l;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	n=read(),m=read(),k=read();
//	cout<<n<<' '<<m<<' '<<k<<endl;
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		e[++cnt]={u,v,w};
		//e[++cnt].u=v,e[cnt].v=u,e[cnt].w=w;
	}
	for(int i=1;i<=k;i++){
		f[i]=read();
		for(int j=1;j<=n;j++){
			tj[i][j]=read();
		}
	}

//	cout<<k*n*n<<endl;
	for(int j=1;j<=n;j++){
		for(int l=j+1;l<=n;l++){
			int ma=1e9;
			for(int i=1;i<=k;i++){
				ma=min(ma,tj[i][j]+tj[i][l]);
			}
			e[++cnt]={j,l,ma};
		}
	}
	//cout<<cnt<<endl;
	int ans=0,sum=0;
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<10005;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
	//	cout<<u<<' '<<v<<' '<<w<<endl;
		int uf=find(u),vf=find(v);
		if(uf!=vf){
			fa[uf]=vf;
	
			ans+=w,sum++;
			//cout<<ans<<endl;
		}
		if(sum==n-1) break;
	}
	cout<<ans<<endl;//17:24ÓĞµã¿¨³£ 
	return 0;
}
