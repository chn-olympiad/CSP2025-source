#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
} 
struct edge{
	int from,to,val;
};
bool cmp(edge a,edge b){
	return a.val<b.val;
}
vector<edge> e;
int n,m,k;
int fa[N+100];
int c[15],a[N][15];
void init(int num){
	for(int i=1;i<=num;i++){
		fa[i]=i;
	}
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e.push_back({u,v,w});
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[j][i]=read();
		}
	}
	for(int i=1;i<=k;i++){
		if(c[i]) flag=1;
	}
	if(!flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e.push_back({n+i,j,a[j][i]});
			}
		} 
	}
	else{
		for(int l=1;l<=k;l++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					e.push_back({i,j,a[i][l]+a[j][l]+c[l]});
				}
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	if(flag){
		int ans=0;
		init(n+k+1);
		for(int i=0;i<e.size();i++){
			int u=e[i].from,v=e[i].to,w=e[i].val;
			int u1=find(u),v1=find(v);
			if(u1==v1) continue;
			fa[u1]=v1;
			ans+=w;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	init(n+k+1);
	for(int i=0;i<e.size();i++){
		int u=e[i].from,v=e[i].to,w=e[i].val;
		int u1=find(u),v1=find(v);
		if(u1==v1) continue;
		fa[u1]=v1;
		ans+=w;
	}
	cout<<ans;
	return 0;
}

