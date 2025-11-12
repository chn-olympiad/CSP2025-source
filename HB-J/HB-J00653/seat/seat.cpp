#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[10001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//ios::sync_with_stdio(Flast);
	//getline(cin,n);
	//getline(cin,m);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		//getline(cin,a[i]);
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+n*m+1);
	int sum;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==a1)
		{
			sum=i;
			break;
		}
	}
	int i1=sum;
	
	int nm1=n*m;
	sum=nm1+1-i1;
	if(sum==m)
	{
		r=(sum/m);
	}
	else
	{
		r=(sum/m)+1;
	}
	if(r==0)
	{
		cout<<n;
	}
	else
	{
		cout<<r<<" ";
	}
	if(r%2==0)
	{
		c=(n+1)-sum%n;
		if(c==0)
		{
			cout<<n;
		}
		else
		{
			cout<<c;
		}
	}
	else
	{
		c=sum%n;
		if(c==0)
		{
			cout<<n;
		}
		else
		{
			cout<<c;
		}
	}
	return 0;
}
