#include<bits/stdc++.h>
using namespace std;
const int N=210;
int a[N],id,n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	id=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		scanf("%d",&a[(i-1)*n+j]);
		if(a[(i-1)*n+j]>a[1])id++;
	}
	int l=(id-1)/n+1;
	int h;
	if(l&1)h=id-(l-1)*n;
	else h=n-(id-(l-1)*n)+1;
	printf("%d %d\n",l,h);
	return 0;
}
