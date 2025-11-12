#include<bits/stdc++.h>
using namespace std;
long long c,r,n,m,a1,a[10000000];
bool cmp(long long x,long long y)
{
	return x>y;
}
string s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>a1;
	a[1]=a1;
	for(long long i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a1)
		{
			c=i/n+1;
			r=i%n;
			if(r==0)
			{
				c--;
				r=n;
			}
			if(c%2==0)
			{
				r=n-r+1;
			}
			cout<<c<<" "<<r;
		}
		else
		{
			continue;
		}
	}
	return 0;
}