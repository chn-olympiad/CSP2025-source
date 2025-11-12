#include<bits/stdc++.h>
using namespace std;
int n,m,x,b;
int a[109];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			b=i;
			break;
		}
	}
	if(b%n==0)
	{
		if((b/n)%2==1)
		{
			cout<<b/n<<" "<<n<<"\n";
			return 0;
		}
		if((b/n)%2==0)
		{
			cout<<b/n<<" "<<"1"<<"\n";
			return 0;
		}
	}
	else
	{
		if((b/n+1)%2==1)
		{
			cout<<b/n+1<<" "<<b%n<<"\n";
			return 0;
		}
		if((b/n+1)%2==0)
		{
			cout<<b/n+1<<" "<<n+1-(b%n)<<"\n";
			return 0;
		}
	} 
	return 0;
} 