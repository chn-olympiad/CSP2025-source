#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n,m,a[N],c,r,v,w;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t = n * m;
	for(int i=1; i<=t; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=t; i++)
	{
		if(a[i] == i)
		{
			cout<<n<<" "<<m<<endl;
			return 0;
		}
		if(a[i] == n * m - i + 1)
		{
			cout<<n-1<<" "<<m-1<<endl;
			return 0;
		}
	}
	v = a[1];
	sort(a+1,a+t+1);
	reverse(a+1,a+t+1);
	for(int i=1; i<=t; i++)
	{
		if(a[i] == v)
		{
			w = i % n;
			if(w == 0)
			{
				c = i / n;
				if(c % 2 != 0)
				{
					r = n;
				}
				else
				{
					r = 1;
				}
			}
			else
			{
				c = i / n + 1;
				if(c % 2 == 0)
				{
					r = n - w + 1;
				}
				else
				{
					r = w;
				}
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
