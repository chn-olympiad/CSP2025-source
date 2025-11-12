#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(edge& e){
		return w<e.w;
	}
}E[1000001];
int s[10001];
int find_set(int x){
	return s[x]==x?x:find_set(s[x]);
}
int kruskal(){
	sort(E+1,E+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		s[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x=find_set(E[i].u),
			y=find_set(E[i].v);
		//cout << x << ' ' << y << endl; 
		if(x!=y)ans+=E[i].w,s[x]=y;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	cout << kruskal();
	return 0;
}

