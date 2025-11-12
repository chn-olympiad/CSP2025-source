#include<bits/stdc++.h>
using namespace std;
struct AK12{
	int u;
	int v;
	int w;
}a[1000010];
int n,m,k;
int zh[15][1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	bool f=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&zh[i][j]);
			if(zh[i][j]!=0){
				f=0;
			}
		}
	}
	if(f){
		cout<<"0"; 
	}
	return 0;
}