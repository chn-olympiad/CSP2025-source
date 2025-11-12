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
	int f=n*m;
	int a[f+1];
	for(int i=1;i<=f;i++)
	{
		cin>>a[i];
	}
	int k=a[1],s=0;
	sort(a+1,a+f+1,cmp);
	for(int i=1;i<=f;i++)
	{
		if(a[i]==k)
		{
			s=i;
			break;
		}
	}
	if(s==1)
	{
		cout<<"1 1";
		return 0;
	}
	if(s>=2&&s<=n)
	{
		cout<<1<<" "<<s;
	}
	int c=0,r=0;
	if(s%n==0)
	{
		c=s/n;
		if((s/n)%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	else
	{
		c=s/n+1;
		if((s/n)%2==0)
		{
			r=s%n;
		}
		else
		{
			r=n+1-s%n;
		}
	}
	cout<<c<<" "<<r; 
	return 0;
}
