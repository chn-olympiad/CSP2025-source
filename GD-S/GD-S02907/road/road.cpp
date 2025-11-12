#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0, f=1;
	char ch=getchar();
	for(ch;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(ch;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
constexpr int INF=1e18, N=1e4+100;
int n, m, k, c[N], dsu[N], ans;
struct edge{
	int u, v, w;
};
inline bool cmp(edge x, edge y){
	return x.w<y.w;	
}
vector<edge> vec;
int find(int x){
	return dsu[x]==x?x:dsu[x]=find(dsu[x]);	
}
void kruskal(){
	sort(vec.begin(), vec.end(), cmp);
	for(auto [u, v, w]:vec){
		int x=find(u), y=find(v);
		if(x!=y){
			dsu[x]=y;
			ans+=w;
		}
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n=read(), m=read(), k=read();
	for(int i=1, u, v, w;i<=m;i++){
		u=read(), v=read(), w=read();
		vec.push_back((edge){u, v, w});	
	}
	for(int i=1;i<=n+k;i++) dsu[i]=i;
	for(int i=n+1;i<=n+k;i++){
		c[i]=read();
		for(int j=1, y;j<=n;j++){
			y=read();
			vec.push_back((edge){i, j, y+c[i]});
		}
	}
	kruskal();
	cout<<ans;
	return 0;
}

