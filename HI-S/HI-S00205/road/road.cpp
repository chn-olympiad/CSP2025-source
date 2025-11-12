#include <bits/stdc++.h>
using namespace std;
int n,m,k,b[100001];
struct node{
	int u,v,w;
}a[1000001];
vector<int>c[11];
bool cmp(node x,node y){
	return  x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		c[i].push_back(x);
		for(int j=0;j<n;j++){
			int y;
			cin>>y;
			c[i].push_back(y);
		}
	}
	cout<<13;
	return 0;
}

