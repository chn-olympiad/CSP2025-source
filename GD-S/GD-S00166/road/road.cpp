#include<bits/stdc++.h>
#define int long long
#define mod 998244353ll
#define pb push_back
using namespace std;
inline int read(){
	int x=0,fl=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
const int maxn=10015;
const int maxk=10;
const int inf=1e9;

int n,m,k,ans;
int f[maxn];
int fd(int x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
struct node{
	int u,v,w;
};vector<node> edge;
bool operator<(node u,node v){return u.w<v.w;}
int w[1<<maxk];
vector<node> e[1<<maxk];
void work(){
	n=read();m=read();k=read();edge.resize(m);
	for(int i=1;i<=m;i++)edge[i-1]={read(),read(),read()};
	sort(edge.begin(),edge.end());
	for(int i=1;i<=n;i++)f[i]=i;
	for(auto[u,v,w]:edge){
		if(fd(u)==fd(v))continue;
		f[fd(u)]=fd(v);
		e[0].pb({u,v,w});
		ans+=w;
	}
	for(int i=0;i<k;i++){
		w[1<<i]=read();e[1<<i].resize(n);
		for(int j=1;j<=n;j++)e[1<<i][j-1]={n+i+1,j,read()};
		sort(e[1<<i].begin(),e[1<<i].end());
	}
	for(int s=1;s<(1<<k);s++){
		int s1=1<<__lg(s),s2=s^s1;
		w[s]=w[s1]+w[s2];
		for(int i=1;i<=n+k;i++)f[i]=i;
		int p1=0,p2=0,res=0;
		vector<node> tmp;
		// cout<<e[s1].size()<<" "<<e[s2].size()<<"\n";
		while(p1<e[s1].size()&&p2<e[s2].size()){
			// if(s==3)cout<<e[s1][p1].w<<" "<<e[s2][p2].w<<"\n";
			if(e[s1][p1].w<=e[s2][p2].w){
				auto[u,v,w]=e[s1][p1];
				if(fd(u)!=fd(v)){
					// if(s==3)cout<<u<<" "<<v<<" "<<w<<" a\n";
					f[fd(u)]=fd(v),res+=w;
					tmp.pb({u,v,w});
				}
				p1++;
			}
			else{
				auto[u,v,w]=e[s2][p2];
				if(fd(u)!=fd(v)){
					f[fd(u)]=fd(v),res+=w;
					// if(s==3)cout<<u<<" "<<v<<" "<<w<<" b\n";
					tmp.pb({u,v,w});
				}
				p2++;
			}
		}
		while(p1<e[s1].size()){
			auto[u,v,w]=e[s1][p1];
			if(fd(u)!=fd(v)){
				f[fd(u)]=fd(v),res+=w;
				tmp.pb({u,v,w});
			}
			p1++;
		}
		while(p2<e[s2].size()){
			auto[u,v,w]=e[s2][p2];
			if(fd(u)!=fd(v)){
				f[fd(u)]=fd(v),res+=w;
				tmp.pb({u,v,w});
			}
			p2++;
		}
		swap(e[s],tmp);
		// cout<<s<<" "<<s1<<" "<<s2<<" "<<res<<" "<<w[s]<<"\n";
		// sort(e[s].begin(),e[s].end());
		ans=min(ans,res+w[s]);
	}
	printf("%lld\n",ans);
}

int T;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	T=1;
	while(T--)work();
}