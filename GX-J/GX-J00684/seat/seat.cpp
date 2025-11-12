#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int l,h,n,a[101],ans,num;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>h>>l;
	n=h*l;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==ans)
		{
			num=i;
			break;
		}
	}
	int e=num/h,d=1;
	if(num%h!=0)
		e++;
	cout<<e<<" ";
	if(e%2==0)
	{
		int ber=num%h;
		d=h+1;
		while(ber!=0)
		{
			ber--;
			d--;
		}
		cout<<d;
		return 0;
	}
	else
	{
		if(num>h)
		{
			num=num%h;
			cout<<num;
			return 0;
		}
		else
		{
			cout<<num;
			return 0;
		}
	}
	return 0;
}
