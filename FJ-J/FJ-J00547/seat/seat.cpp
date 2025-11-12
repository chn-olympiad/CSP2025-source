#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m>>a[1];
	s=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			int c=i/n,r=i%n;
			if(r==0)
			{
				r=n;
			}
			else
			{
				c++;
			}
			if(c%2==0)
			{
				r=n-r+1;
			}
			cout<<c<<" "<<r;
			break;
		}
	}
	return 0;
}
