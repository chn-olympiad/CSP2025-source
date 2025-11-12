#include <bits/stdc++.h>
using namespace std;
bool cmp(int c,int b)
{
	if (c>=b)
	{
		return c>b;
	}
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],num=0,mum=0;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==sum)
		{
			mum+=i/n;
			if (i%n!=0)
			{
				mum++;
			}
			if (mum%2==0)
			{
				num=n-i%n;
			}
			else
			{
				if (i%n==0 && i/n==1)
				{
					num=i;
				}
				else if(i%n==0 && i/n!=1)
				{
					num=i/n;
				}
				else
				{
					num=i%n;
				}
			}
			break;
		}
	}
	cout<<mum<<" "<<num;
	return 0;
}
