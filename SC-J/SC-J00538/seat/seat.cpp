#include<bits/stdc++.h>
using namespace std;
int readin()
{
	char st;
	int res=0;
	st=getchar();
	while(st>='0'&&st<='9')
	{
		res=res*10+st-'0';
		st=getchar();
	}
	return res;
}
int n,m;
int a[105];
int flag;
int d;
int ans1,ans2;
bool cmp(int x,int y)
{
	return x>y;
}
void f(int x)
{
	ans1=x/n;
	int t=x%n;
	if(t>=1)
	{
		ans1++;
	}
	if(t==0)
	{
		if(ans1%2==1)
		{
			ans2=n;
		}
		else
		{
			ans2=1;
		}
	}
	else
	{
		if(ans1%2==1)
		{
			ans2=t;
		}
		else
		{
			ans2=n-t+1;
		}
	}
	return ;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=readin();
	m=readin();
	for(int i=1;i<=n*m;i++)
	{
		a[i]=readin();
		if(i==1)
		{
			flag=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==flag)
		{
			d=i;
			break;
		}
	}
	f(d);
	cout<<ans1<<" "<<ans2;
	return 0;
}