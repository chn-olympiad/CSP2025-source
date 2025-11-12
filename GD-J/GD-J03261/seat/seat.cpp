#include<iostream> 
#include<cstdio> 
#include<cmath> 
#include<string.h>
using namespace std;
struct node
{
	int marks=-1;
	bool f=0;
}a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[1].f=1;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i].marks;
	}
	for(int i=1;i<n*m;i++)
	{ 
		for(int j=m*n;j>i;j--)
		{
			if(a[j].marks>a[j-1].marks)
			{
				swap(a[j],a[j-1]);
			}
		}
	}
	int c=1,r=1,s=0;
	while(a[s+1].marks!=-1)
	{
		if(a[++s].f==1)
		{
			cout<<c<<" "<<r;
			break;
		}
		if(c%2==0)
		{
			if(r==1)
			{
				++c;
				continue;
			}
			else
			{
				--r;
				continue;
			}
		}
		else
		{
			if(r==n)
			{
				++c;
				continue;
			}
			else
			{
				++r;
				continue;
			}
		}
	}
	return 0;
} 
