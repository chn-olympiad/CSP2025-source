#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+t+1,cmp);
	int h=0,l=0;
	for(int i=1;i<=t;i++)
	{
		if(a[i]==r)
		{
			int ys=i%n;
			if(ys==0)
			{
				l=i/n;
				if(l%2!=0)
				{
					h=n;
				}
				else
				{
					h=1;
				}
			}
			else
			{
				l=i/n+1;
				if(l%2==0)
				{
					h=n-ys+1;
				}
				else
				{
					h=ys;
				}
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
