#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],k,num1,num2,jb;
bool cmp(long long x,long long y)
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
			jb=i;
			break;
		}
	}
	if(jb%n==0)
	{
		num1=(jb/n);
	}
	else
	{
		num1=(jb/n)+1;
	}
	if(num1%2==1)
	{
		if(jb%n==0)
		{
			num2=n;
		}
		else
		{
			num2=jb%n;
		}
	}
	else
	{
		if(jb%n==0)
		{
			num2=1;
		}
		else
		{
			num2=n-(jb%n)+1;
		}
	}
	cout<<num1<<" "<<num2;
	return 0;
} 
