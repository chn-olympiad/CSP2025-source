#include<bits/stdc++.h>
using namespace std;
int ms;//总数 
long long int ml;//总长 
int ma;//最长 
int a[100000];
long long int ans=0;
bool yu(int x,int y)
{
	int i;
	i=1<<y;
	if((x&i)==0)
	{
		return false;
	}else
	{
		return true;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool q=true;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			q=false;
		}
	}
	if(q)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=(n-i-1);
			if(i==3)
			{
				ans=ans/(n-2);
				ans=ans/(n-3);
			 } 
			
		}
		ans%=998244353;
		cout<<ans;
		return 0;
	}
	for(int i=7;i<pow(2,n);i++)
	{
		ms=0;
		ml=0;
		ma=0;
		for(int j=0;j<n;j++)
		{
			if(yu(i,j))
			{
				ms++;
				ml+=a[j];
				ma=max(a[j],ma);
			}
		}
		if(ms>=3&&(ma*2)<ml)
		{
			ans++;
		}
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}
