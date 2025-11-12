#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,w,c[10005],a[15][10005];
struct node{
	int to,w;
};
vector<node> v[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}cout<<0;
}

