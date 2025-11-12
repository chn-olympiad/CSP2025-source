#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct city{
	int u,v,w;
};
struct country{
	int c,a[1010];
};
city ci[1010];
country co[15];
int mian(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>ci[i].u>>ci[i].v>>ci[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>co[i].c;
		for(int j;j<=n;j++){
			cin>>co[i].a[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
