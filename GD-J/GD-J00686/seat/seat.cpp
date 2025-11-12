#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[1005];

int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	
	cin>>n>>m;
	long long k = n*m;
	for(long long i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	long long t = a[1],ans;
	sort(a+1,a+k+1);
	for(long long i=k;i>=1;i--)
	{
		if(t == a[i]){
			ans = k-i+1;
			break;
		}
	}
	long long l = (ans - 1) / n + 1;
	
	
	if(l % 2 == 1)
	{
		cout<<l << ' ' << ans - (l-1)*n;
	}else{
		cout<<l<<' '<<l*n-ans+1;
	}
	return 0;
}
