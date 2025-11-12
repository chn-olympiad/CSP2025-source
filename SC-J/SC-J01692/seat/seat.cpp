#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long n=1,m,a[N];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long sum=1ll*n*m;
	for(int i=1;i<=sum;i++) cin>>a[i];
	long long pos=a[1];
	sort(a+1,a+sum+1,cmp);
	long long ans=0;
	for(int i=1;i<=sum;i++)
	{
		if(a[i]!=pos) ans++;
		else
		{
			ans++;
			break;
		}
	}
	if(ans%n==0)
	{
		cout<<ans/n<<' ';
		if((ans/n)%2==0) cout<<1;
		else cout<<n;
	}
	else if(ans%n!=0)
	{
		cout<<(ans/n)+1<<' ';
		if(((ans/n)+1)%2==0) cout<<(n-ans%n)+1;
		else cout<<ans%n;
	}
	return 0;
}