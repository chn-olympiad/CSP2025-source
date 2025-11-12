#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110],t,x;
bool cmp(int x,int y)
{
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			x=i;
		}
	}
	if(x%n==0)
	{
		if(x/n%2==1)
		{
			cout<<x/n<<" "<<n;
		}
		else if(x/n%2==0)
		{
			cout<<x/n<<" "<<"1";
		}
	}
	else
	{
		if((x/n+1)%2==1)
		{
			cout<<x/n+1<<" "<<x%n;
		}
		else if((x/n+1)%2==0)
		{
			cout<<x/n+1<<" "<<n-x%n+1;
		}
	}
	return 0;
}
