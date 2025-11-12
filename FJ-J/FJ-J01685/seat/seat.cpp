#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;i++)
	{
		scanf("%d",&a[i]);
	}
	int sc=a[1],ra;
	sort(a+1,a+nm+1);
	for(int i=nm;i;i--)
	{
		if(a[i]==sc)
		{
			ra=nm-i+1;
			break;
		}
	}
	int r=ra/n,b=ra%n;
	r++;
	if(!b)
	{
		r--,b=n;
	}
	if(r%2)
	{
		printf("%d %d",r,b);
	}
	else
	{
		printf("%d %d",r,n+1-b);
	}
	return 0;
}
