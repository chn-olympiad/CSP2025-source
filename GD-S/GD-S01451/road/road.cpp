#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1e6+10;
int gai[N];
struct edge{
	int to,int length;
	bool operator>(const edge& other) const{
		return length>other.length;
	}
};
int n,m,k;
vector<edge>graph[N];
void dij(){
	
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	for(int i=1;i<=k;++i){
		int x;
		cin>>x;
		for(int j=1;j<=n;++j){
			cin>>x;
			graph[]
		}
	}
	dij();
	return 0;
}

