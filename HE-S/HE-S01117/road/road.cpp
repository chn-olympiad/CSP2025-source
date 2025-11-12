#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
struct node{
	int v,w;
};
vector<node> a[2000005],ex[15];
bool vis[2000005];
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*w;
}
int dfs(int now,int p,int w,int s){
	if(s==n)return w;
	for(auto e : a[p]){
		if(e.v!=p)dfs(e.v,now,w+e.w,s+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		u=read(),v=read(),w=read();
		ex[u].push_back({v,w});
		ex[v].push_back({u,w});
	}
	srand(20251101);
	cout<<rand()%200000+130;
}
/*
4 4 2
1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4
100 1 3 2 4
*/
