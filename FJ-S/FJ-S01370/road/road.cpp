#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[15][1000005];
long long ans;

struct gg{
	int u,v,w;
}a[1000005];

bool cmp(gg x,gg y){
	return x.w>y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i][0]);
		for(int j=1;j<=m;j++){
			scanf("%d",&b[i][j]);
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		ans=ans+a[i].w;
	}
	cout<<ans;
	return 0;
} 
