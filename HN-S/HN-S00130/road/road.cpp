#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
};
node l[1000007];
int a[17][10007];
int c[17];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d",&l[i].u,&l[i].v,&l[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cout<<0;
	return 0;
}
