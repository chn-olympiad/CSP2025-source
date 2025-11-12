#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m],b;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+(n*m),cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==r)b=i;
	}
	cout<<(b/n)+1<<" ";
	if(b%(2*n)<n)
	{
		if((b+1)%n==0)
		{
			cout<<n;
			return 0;
		}
		cout<<(b+1)%n;
	}
	else if(b%(2*n)>=n)
	{
		if(b%n==0)
		{
			cout<<n;
			return 0;
		}
		cout<<n-((b+1)%n);
	}
	return 0;
}
