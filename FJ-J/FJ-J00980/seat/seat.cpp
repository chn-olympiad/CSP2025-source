#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ansx,ansy;
int n,m;
int a[N],tot;
int fir,h;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	fir=a[1];
	//printf("%d\n",fir);
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==fir)
		{
			tot=i;
		}
	}
	//printf("%d\n",tot);
	if(tot%n==0)
	{
		ansy=tot/n;
	}
	else
	{
		ansy=tot/n+1;
	}
	if(ansy%2==1)
	{
		if(tot==n)
		{
			ansx=n;
		}
		else
		{
			ansx=tot%n;
		}
	}
	else
	{
		ansx=n-(tot%n)+1;
	}
	printf("%d %d",ansy,ansx);
}
