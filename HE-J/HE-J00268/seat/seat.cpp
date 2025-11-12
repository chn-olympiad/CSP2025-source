#include <bits/stdc++.h>
using namespace std;
int paiwei(int a,int b)
{
	if(a%b==0)
	{
		cout<<a/b<<" ";
		if(a<=b)
		{
			cout<<a;
		}
		else
		{
			if((a/b)%2==0)
			{
				cout<<1;
			}
			else
			{
				cout<<b;
			}
		}
	}
	else
	{
		cout<<a/b+1<<" ";
		if(a<=b)
		{
			cout<<a;
		}
		else
		{
			if((a/b)%2==0)
			{
				cout<<a%b;
			}
			else
			{
				cout<<b+1-a%b;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105]={0},b[105]={0};
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int sum=a[0];
	int x;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=0;j<n*m;j++)
		{
			if(b[i]<a[j])
			{
				b[i]=a[j];
				x=j;
			}
		}
		a[x]=0;
	}
	int ans=0;
	for(int i=1;i<=n*m;i++)
	{
        if(b[i]==sum)ans=i;
	}
	paiwei(ans,n);
	return 0;
}
