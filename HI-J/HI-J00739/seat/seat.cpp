#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],n,m,r;
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
	r=a[1];
	int now=-1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			now=i;
			break;
		}
	}
	cout<<(now-1)/n+1<<' ';
	if(((now-1)/n+1)%2)
	{
		if(now%n!=0)
		cout<<now%n;
		else cout<<n;
	}
	else 
	{
		cout<<n-(now-1)%n;
	}
	cout<<now;
	return 0;
}
