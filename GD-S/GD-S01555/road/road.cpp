#include <iostream>
#include <cstdio>
using namespace std;
struct road{
	int u,v,w;
};
struct village{
	int c,a[10005];
};
int m,n,k;road rs[1000005];village vs[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) cin>>rs[i].u>>rs[i].v>>rs[i].w;
    for (int i=1;i<=k;i++){
    	cin>>vs[i].c;
    	for (int j=1;j<=n;j++) cin>>vs[i].a[j];
	}
	
	return 0;
} 
