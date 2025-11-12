#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],mingci,yy1,lie;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[0];
	sort(a,a+(n*m),cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==t)
		{
			mingci=i+1;
		}
	}
	lie=mingci/n;
	if(mingci%n==0)
	{
		if(lie%2==0)
		{
			yy1=1;
		}
		else
		{
			yy1=n;
		}
	}
	else
	{
		if(mingci<n)
		{
			yy1=mingci%n;
			lie++;
		}
		else
		{
			if((lie+1)%2==0)
			{
				yy1=n-(mingci%n)+1;
				lie++;
			}
			else
			{
				yy1=mingci%n;
				lie++;
			}
		}
	}
	cout<<lie<<" "<<yy1;
	return 0;
}
