#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,t,a[n],b[n],c[n],g;
	g=0;
	scanf("%ld",&n);
	scanf("%ld",&m);
	scanf("%ld",&t);
	for(int i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
		scanf("%ld",&b[i]);
		scanf("%ld",&c[i]);
	}
	for(int i=0;i<n;i++)
	{
		g=min(a[i+2],b[i+2]);
		g=min(g,c[i+2]);
	}
	printf("%ld",g);
	return 0;
}
