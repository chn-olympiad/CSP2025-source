#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int t;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==t)
		{
			t=i;
		}
	}
	cout<<t/n+1<<" ";
	if((t/n)%2==0)
	{
		cout<<n-t%n+1;
	}
	else
	{
		if(t%n!=0)
		{
			cout<<t%n;
		}
		else
		{
			cout<<n;
		}
	}
	return 0;
}