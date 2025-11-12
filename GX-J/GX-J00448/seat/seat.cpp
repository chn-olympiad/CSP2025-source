#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const int N=1e5+91,G=5e2+5,inf=0x7fffffff;
int a[N];
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	f(i,1,n*m) cin>>a[i];
	int xr=a[1],id=0;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==xr) id=n*m-i+1;
	}
	if(id%n==0)
	{
		if((id/n)%2==1) cout<<id/n<<" "<<m;
		else cout<<n<<" "<<1;
	}
	else if(id%n!=0)
	{
		if((id/n)%2==1) cout<<id/n+1<<" "<<m-(id%n)+1;
		else cout<<id/n+1<<" "<<id%n;
	}
	return 0;
}

























