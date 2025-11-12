#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e6+10;
struct edge{
	int u,v,w;
	friend bool operator<(edge x,edge y){
		return x.w<y.w;
	}
}e[M];
int n,m,k,cnt,minn[N],c[15],a[N],sz,ans,f[N],es,siz[N];
vector<bool>use(12);
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
inline void init(){
	for(int i=1;i<=n+k;i++)f[i]=i;
}
inline void merge(int x,int y){
	if(siz[x]<=siz[y])f[x]=y,siz[y]+=siz[x];
	else f[y]=x,siz[x]+=siz[y];
}
inline void kruskal(){
	sz=0;
	init();
	for(int i=1;i<=cnt&&sz<es;i++){
		int a=find(e[i].u),b=find(e[i].v);
		if(e[i].v>n)
			if(!use[e[i].v-n-1])
				continue;
		if(a!=b){
			sz++;
			ans+=e[i].w;
			f[a]=b;
		}
	}
}
inline void kruskal2(){
	for(int i=1;i<=m&&sz<n;i++){
		int a=find(e[i].u),b=find(e[i].v);
		if(a!=b){
			sz++;
			ans+=e[i].w;
			merge(a,b);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	if(k==0){
		for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
		sort(e+1,e+m+1);
		kruskal2();
		cout<<ans<<endl;
		return 0;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			e[++cnt]={j,i+n,a[j]};
		}
	}
	sort(e+1,e+cnt+1);
	es=n;
	kruskal();
	int res=ans;
	for(int i=1;i<=k;i++){
		
		for(int j=0;j<n;j++)
			use[j]=((j<i)?1:0);
		es++;
		do{
			ans=0;
			for(int j=0;j<n;j++)if(use[j])ans+=c[j+1];
			kruskal();
			res=min(res,ans);
		}while(next_permutation(use.begin(),use.begin()+i));
	}
	cout<<res<<endl;
	return 0;
}
//16:37 1h后没有正解思路，但是部分分可做？
//没能写出正解，AFO力 
