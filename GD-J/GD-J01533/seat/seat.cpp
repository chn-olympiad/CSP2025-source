#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],k;
	bool A=1,B=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=i) A=0;
		if(a[i]!=n*m-i+1) B=0;
	}
	if(A)
		printf("%d %d",n,m);
	else if(B)
		printf("1 1");
	else
	{
		a[0]=a[1];
		sort(a+1,a+n*m+1,cmp);
		for(int i=1;i<=n*m;i++)
			if(a[i]==a[0])
			{
				k=i;
				break;
			}
		int c=(k+n-1)/n,r=k-(c-1)*n;
		if(c%2==0)
			r=n-r+1;
		printf("%d %d",c,r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
