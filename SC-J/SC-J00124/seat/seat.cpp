#include<bits/stdc++.h>
using namespace std;
int i,j,c=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000];
	scanf("%d%d%d",&n,&m,&a[0]);
	for(i=1;i<n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[0])
		c++;
	}
	int l=c/n+(c%n!=0),h;
	if(l%2==0)
	h=n-c%n+1;
	else
	h=c%n;
	if(h==0)h=n;
	else if(h==n+1)h=1;
	printf("%d %d",l,h);
	return 0;
} 	