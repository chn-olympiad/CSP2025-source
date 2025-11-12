#include <bits/stdc++.h>
using namespace std;
long long a[100005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	long long y=a[1];
	sort(a+1,a+n*m+1,cmp);
	long long x=0;
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==y)
		{
			x=i;
			break;
		} 
	}
    if(x%n==0)
	{
		long long p=x/n;
		cout<<p<<" ";
		if(p%2==0) cout<<1;
		else cout<<n;
	} 
	else
	{
		long long q=x/n+1;
		cout<<q<<" ";
		if(q%2==0) cout<<n-x%n+1;
		else cout<<x%n;
	}
	return 0;
}