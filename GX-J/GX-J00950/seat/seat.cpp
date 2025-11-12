#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,v,o,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(p==a[i])
		{
			v=i;
			break;
		}
	}
	num=v;
	for(int i=1;i<=m;i++)
	{
		if(v<=n*i)
		{
			o=i;
			break;
		}
		num-=n;
	}
	if(o%2==0)
	{
		cout<<o<<" ";
		if(num==0)
		{
			cout<<1;
		}
		else if(num==n-1)
		{
			cout<<n;
		}
		else
		{
			cout<<n-num+1;
		}
	}
	else
	{
		cout<<o<<" "<<num;
	}
	return 0;
}
