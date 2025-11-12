#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    long long a[n+1]; 
    for(long long i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		long long x=max(max(a[1],a[2]),a[3]),sum=0;
		for(long long i=1;i<=3;i++)
		{
			sum+=a[i];
		}
		if(sum>x*2) cout<<1;
		else cout<<0;
	}
	return 0;
}