#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ai3 array<int,3>
using namespace std;
const int N=1e4+15;
vector<ai3>g;
vector<pii>e[N];
int n,m,k;
int fa[N];//¿ËÂ³Ë¹¿¨¶ûËã·¨
int c[N];
void read(int &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
}
int find(int x){
	return fa[x]<0?x:(fa[x]=find(fa[x]));
}
int merge(int x,int y){
	int a=find(x),b=find(y);
	if(a==b)return a;
	if(fa[a]<fa[b]){
		fa[a]+=fa[b];
		fa[b]=a;
		return a;
	}else{
		fa[b]+=fa[a];
		fa[a]=b;
		return b;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=n;i++)fa[i]=-1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u);
		read(v);
		read(w);
		ai3 fr;
		fr[0]=w,fr[1]=u,fr[2]=v;
		g.push_back(fr);
	}
	sort(g.begin(),g.end()); 
	for(auto x:g){
		if(find(x[1])!=find(x[2])){
			merge(x[1],x[2]);
			e[x[1]].push_back({x[2],x[0]});
			e[x[2]].push_back({x[1],x[0]});
		}
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			e[n+i].push_back({j,a});
			e[j].push_back({n+i,a});
		}
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++)fa[j]=-1;
		g.clear();
		for(int j=1;j<=n;j++){
			for(auto x:e[j]){
				if(x.first>n&&!((i>>(x.first-n-1))&1))continue;
				ai3 fr;
				fr[0]=x.second,fr[1]=x.first,fr[2]=j;
				g.push_back(fr);
			}
		}
		sort(g.begin(),g.end());
		ll sum=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1)sum+=c[j];
		}
		for(auto x:g){
			if(find(x[1])!=find(x[2])){
				merge(x[1],x[2]);
				sum+=x[0];
			}
		} 
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
