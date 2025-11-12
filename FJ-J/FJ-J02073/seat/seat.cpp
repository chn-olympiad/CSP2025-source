#include<iostream>
#include<algorithm>
using namespace std;
int n=0,m=0,l,q=0,w=0;
int a[105]={};
int p[13][13]={};
bool cmd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	l=n*m;
	for(int k=0;k<l;k++)
	{
		scanf("%d",&a[k]);
	}
	w=a[0];
	sort(a,a+l,cmd);
	for(int k=1;k<=m;k++)
	{
		if(k%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				p[k][i]=a[q];
				if(a[q]==w)
				{
					cout<<k<<' '<<i;
					return 0;
				}
				q++;
			}
		 } 
		else
		{
			for(int i=n;i>=1;i--)
			{
				p[k][i]=a[q];
				if(a[q]==w)
				{
					cout<<k<<' '<<i;
					return 0;
				}
				q++;
			}			
		}
	}
}
