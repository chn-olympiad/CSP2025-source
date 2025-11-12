#include<bits/stdc++.h>
using namespace std;
int n,m[5010];

bool f(int l,int r)
{
	int k = 0,s = 0;
	for(int i =1;i<=n;i++)
	{
		k+=m[i];
		s = max(s,m[i]);
	}
	if(k > 2 * s)
		return 1;
	return 0;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i =1;i<=n;i++)
		cin >>m[i];
	if(n == 3)
	{
		if(f(1,n))
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	return 0;
}
