#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int s=0;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==num)
		{
			s=i;
			break;
		}
	}
	int x=0;
	if (s%n==0)
	{
		x=s/n;
		cout<<s/n;
		cout<<" ";
	}
	else
	{
		x=s/n+1;
		cout<<s/n+1;
		cout<<" ";
	}
	if (x%2==1)
	{
		cout<<(s-1)%n+1;
	}
	else
	{
		cout<<n-((s-1)%n+1)+1;
	}
	return 0;
}
