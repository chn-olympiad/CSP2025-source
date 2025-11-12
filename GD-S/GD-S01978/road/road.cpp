#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,f[N];
long long ans=0;
struct node{
	long long x,w;
};
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
vector<node>e[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
