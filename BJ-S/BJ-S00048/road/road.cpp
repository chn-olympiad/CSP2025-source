#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct bian{
	int to,weight;
};
vector <bian> s[10004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	bian t1,t2;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		t1.to=v;
		t1.weight=w;
		s[u].push_back(t1);
		t2.to=u;
		t2.weight=w;
		s[v].push_back(t2);
	}
	
	return 0;
}
