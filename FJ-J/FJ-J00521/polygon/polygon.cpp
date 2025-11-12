#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 998244353;
int n,a[N],sum,cnt;
int ma = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(a[j] > ma)
			{
				ma = a[j];
			}
			sum += a[j];
			if(j >= 3 && sum > ma * 2)
			{
				cnt++;
			}
		}
	}
	cout<<cnt%M;
	return 0;
}
