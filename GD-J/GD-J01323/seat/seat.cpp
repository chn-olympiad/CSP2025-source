#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000009],x;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		scanf("%lld",&a[i]);
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
    	if(x==a[i])
		{
			long long h=(i-1)/n+1;
			if(h%2==1)cout<<h<<" "<<i-(h-1)*n;
			else cout<<h<<" "<<n-(i-(h-1)*n)+1;
			exit(0);
		}
	}

	return 0;
}
