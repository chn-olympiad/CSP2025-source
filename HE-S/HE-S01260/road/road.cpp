#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,M=1e4+10;
template<typename T>void read(T&x){
	int f=1;x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));x=x*f;
}
int n,m,k,fa[N],ans;
struct node{
	int a,b,w;
}x[N];
//vector<pair<int,int> >q[N];
//priority_queue<pair<int,int> > p;
//bool vis[N];
//void dij(int s){
//	for(int i=0;i<=n+5;i++)dis[i]=0x3f3f3f3f;
//	d[s]=0;p.push({0,s});
//	while(!q.empty()){
//		int x=p.top().first;p.pop();
//		if(!vis[x])continue;vis[x]=1;
//		for(auto j:q[x]){
//			int u=j.first;
//			if(d[u]>d[x]+j.second){
//				d[u]=d[x]+j.second;
//				q.push({-d[x]+j.second,u});
//			}
//		}
//	}
//}
int find(int x){
	return fa[x]==x?x:fa[x]=find(x);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		read(x[i].a);read(x[i].b);read(x[i].w);
//		fa[x[i].a]=x[i].b;
	}
	int cnt=0;
	if(k==0){
		sort(x+1,x+1+m,cmp);
//	for(int i=1;i<=n;i++)cout<<fa[i];
		for(int i=1;i<=m;i++){
			int tx=find(x[i].a),ty=find(x[i].b);
			if(tx!=ty){
				fa[tx]=ty;
				ans+=x[i].w;
//				cout<<ans;
			cnt++;
			}
			if(cnt==n-1)break;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
/*
4 6 0
1 2 1
1 3 5
1 4 4
2 3 2
2 4 5
3 4 3

*/

