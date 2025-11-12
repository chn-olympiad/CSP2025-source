#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct roads{
	int u,v,w;
};
struct roads road[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>road[i].u>>road[i].v>>road[i].w;
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		for(int j=0;j<n;j++){
			int u;
			cin>>u;
			road[i+n].u = n+i;
			road[i+n].v = j;
			road[i+n].w = u;
		}
	}
	
	return 0;
}
