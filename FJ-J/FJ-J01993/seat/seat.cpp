#include<bits/stdc++.h>
using namespace std;
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
	long long a[n*m+5];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	long long x=a[0],y;
	sort(a,a+(m*n),cmp);
	for(long long i=0;i<n*m;i++)
	{
		if(a[i]==x) y=i+1;
	}
	cout<<ceil(y/1.0/n)<<" ";
	if(int(ceil(y/1.0/n)) %2)
	{
		if(y%n==0) cout<<n;
		else cout<<y%n;
	}
	else cout<<n-y%n+1;
	return 0;
}
