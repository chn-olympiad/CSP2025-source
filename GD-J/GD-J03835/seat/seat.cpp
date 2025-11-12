#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[115],r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			if(i%n==0)cout<<i/n<<' ';
			else cout<<i/n+1<<' ';
			if((i-1)/n%2==0) cout<<1+((i-1)%n);
			else cout<<n-i%n+1;
			return 0;
		}
	}
}

