# include <bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1],gs=n*m;
	sort(a+1,a+gs+1,cmp);
	for(int i=1;i<=gs;i++)
	{
		if(a[i]==x)
		{
			x=i;
			break;
		}
	}
	int h,l;
	if(x%n==0) l=x/n;
	else l=x/n+1;
	if(l%2==1)
	{
		h=x%n;
		if(!h) h=n;
	}
	else
	{
		h=n-x%n+1;
	}
	printf("%d %d",l,h);
	return 0;
}
