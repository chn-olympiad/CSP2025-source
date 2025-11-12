#include<iostream>
#include<algorithm>
using namespace std;
bool yw(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,wu,r,k=1,l=0;
	int a[400]={0};
	int b[20][20]={0};
	bool f=false;
	cin>>n>>m;
	wu=n*m;
	for(int i=1;i<=wu;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+wu+1,yw);
	for(int i=1;i<=wu;i++)
	{
		if(f==false)
		{
			l++;
			b[l][k]=a[i];
			if(l==n)
			{
				k++;
				l=n+1;
				f=true;
				continue;
			}
		}
		else
		{
			l--;
			b[l][k]=a[i];
			if(l==1)
			{
				k++;
				l=0;
				f=false;
				continue;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==r)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}