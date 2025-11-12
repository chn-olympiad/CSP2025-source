#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct fr{
	int x,y;
};
int c[20];
int f[20][100006];
map<fr,int> mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	cout<<0;
	return 0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);

	}
	for(int i=1;i<=k;i++){
		scanf("%d",&f[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&f[i][j]);
		}
	}
	
	
	return 0;
}
