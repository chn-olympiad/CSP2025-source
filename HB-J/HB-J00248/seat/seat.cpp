#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,h;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			h=i;
		}
	}
	if(((h-1)/n)%2==0)
	{
		if(h%n==0)
			cout<<(h+n-1)/n<<" "<<n;
		else
			cout<<(h+n-1)/n<<" "<<h%n;
	}
	else
	{
		if(h%n==0)
			cout<<(h+n-1)/n<<" "<<1;
		else
			cout<<(h+n-1)/n<<" "<<n-(h%n)+1;
	}
	return 0;
}
