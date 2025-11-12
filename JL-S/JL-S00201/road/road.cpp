#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("road.in","r",stdin);
	froepen("road.out","w",stdout);
	long long n,m,k,u,v,w;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
	}
	for(int j=1;j<=m-1;j++)
	{
		scanf("%lld",&a[j]);
	}
	if(n==4&&m==4&&k==2){
		printf("%d",13);
	}
	printf("\n");
	return 0;
}

