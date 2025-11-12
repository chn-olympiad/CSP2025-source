#include<bits/stdc++.h>
using namespace std;
long long x,y,s[100],a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i = 0;i<x*y;i++)
	{
		cin>>s[i];
	}
	a = s[0];
	sort(s,s+x*y);
	for(int i = 0;i<=x*y/2-1;i++)
	{
		long long k;
		k = s[i];
		s[i] = s[x*y-i-1];
		s[x*y-i-1] = k;
	}
	for(int i = 1;i<=x;i++)
	{
		for(int j = 1;j<=y;j++)
		{
			if (s[(i-1)*y+j-1] == a)
			{
				if (i%2 != 0) cout<<i<<" "<<j;
				else cout<<i<<" "<<y-j+1;
				return 0;
			}
		}
	}
	return 0;
}

