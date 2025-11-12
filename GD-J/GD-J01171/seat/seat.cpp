#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ll=n*m;
	int r;
	for(int i=1; i<=ll; i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+ll+1,cmp);
	for(int i=1; i<=ll; i++)
	{
		if(a[i]==r)
		{
			r=i;
			break;
		}
	}
	int ansx=0,ansy=0;
	ansy=r/(2*n);
	int snack=r%(2*n);
	if(snack==0)
	{
		ansx=1;
		ansy*=2;
	}
	else if(snack<=n)
	{
		ansx=snack;
		ansy=ansy*2+1;
	}
	else
	{
		int snack2=snack-n;
		ansx=n-snack2+1;
		ansy=ansy*2+2;
	}
	printf("%d %d\n",ansy,ansx);
	return 0;
 } 
