#include<bits/stdc++.h>
using namespace std;
int n=0,a[1145140],p=0,cnt=0;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n*p;i++)
	{
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*p+1,cmp);
	for(int i=1;i<=n*p;i++)
	{
		if(a[i]==cnt)
		{
			cnt=i;
			break;
		}
	}
	if((cnt/n)%2==0)
	{
		if(cnt%n<=0)
		{
			cout<<cnt/n<<" "<<1;
			return 0;
		}
		cout<<cnt/n+1<<" "<<cnt%n;
		return 0;
	}
	else
	{
		if(cnt%n<=0)
		{
			cout<<cnt/n<<" "<<n;
			return 0;
		}
		cout<<cnt/n+1<<" "<<n-cnt%n+1;
		return 0;
	}
	return 0;
}
