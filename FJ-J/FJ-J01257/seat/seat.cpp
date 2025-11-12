#include<bits/stdc++.h>
using namespace std;
int a[150],n,m,r,wz;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	a[1]=r;
	for(int i=2;i<=n*m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m/2;i++)	
		swap(a[i],a[n*m-i]);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r)
		{
			wz=i;
			break;
		}
	if((wz/n)%2==0)
		printf("%d %d",wz/n+1,wz%n+1);
	else
		printf("%d %d",wz/n+1,m-wz%n);
	return 0;
}

