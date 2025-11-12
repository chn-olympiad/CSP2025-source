#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4,M=1e6,K=10,INF=1e17;
int n,m,k;
int tot,ans=INF;
int c[K+5],cc[K+5] [N+5];
int fa[N+K+5];
struct Node{
	int u,v,w;
}e[M+K*N+5],ee[M+5];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int Kruskal(int tmp,int sum){
	if(sum>=ans)
		return INF;
	for(int i=1;i<=n+k;++i)
		fa[i]=i;
	sort(e+1,e+1+tot,cmp);
	int cnt=0,res=sum;
	for(int i=1;i<=tot;++i){
		if(res>=ans)
			return INF;
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			res+=e[i].w;
			++cnt;
			fa[f2]=f1;
			if(cnt==n+tmp-1)
				return res;
		}
	}
	return res;
}
bool check(){
	for(int i=1;i<=k;++i){
		if(c[i]!=0)
			return false;
		bool flag=false;
		for(int j=1;j<=n;++j)
			if(cc[i] [j]==0){
				flag=true;
				break;
			}
		if(!flag)
			return false;
	}
	return true;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
		ee[i].u=e[i].u,ee[i].v=e[i].v,ee[i].w=e[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>cc[i] [j];
	}
	if(check()){
		tot=m;
		for(int i=1;i<=k;++i)
			for(int j=1;j<=n;++j){
				++tot;
				e[tot].u=j;
				e[tot].v=i+n;
				e[tot].w=cc[i] [j];
			}
		ans=Kruskal(k,0);
	}
	else{
		for(int S=0;S<=(1<<k)-1;++S){
			tot=m;
			int tmp=0,sum=0;
			for(int j=1;j<=k;++j)
				if(S&(1<<k-j)){
					++tmp;
					sum+=c[j];
					for(int l=1;l<=n;++l){
						++tot;
						e[tot].u=l;
						e[tot].v=j+n;
						e[tot].w=cc[j] [l];
					}
				}
			if(sum>=ans)
				continue;
			for(int i=1;i<=m;++i)
				e[i]=ee[i];
			ans=min(ans,Kruskal(tmp,sum));
		}
	}
	cout<<ans;
	return 0;
}

