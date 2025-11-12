#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c=1,r;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(c%2==1)
		{
			r++;
			if(r>m)
			{
				c++;
				r=m;
			}
		}
		else
		{
			r--;
			if(r==0)
			{
				c++;
				r=1;
			}
		}
		if(a[i]==b)
		{
			cout<<c<<" "<<r;
			break;
		}
	}
	return 0;
}

