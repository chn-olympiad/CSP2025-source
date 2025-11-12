#include<bits/stdc++.h>
using namespace std;
struct ren{
	int x,y,z;
}a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=k;i++){
		int df1,df;
		scanf("%d",&df1);
		for(int j=1;j<=n;j++) scanf("%d",&df);
	}
	for(int i=1;i<=n;i++){
		ans+=a[i].z;
	}
	printf("%lld",ans);
	return 0;
} 
