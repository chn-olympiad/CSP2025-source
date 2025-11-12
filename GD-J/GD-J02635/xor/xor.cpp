#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+100;
int n,k,ct,ans;
int a[N];
bool flag[N];

bool f(int a,int b)
{
	for(int i=a;i<=b;i++)
	{
		if(flag[i]==1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ct++;
			flag[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=a[i];
		for(int j=i+1;j<=n;j++)
		{
			ans^=a[j];
			if(ans==k && f(i,j))
			{
				ct++;
				for(int k=i;k<=j;k++)
				{
					flag[k]=1;
				}
			}
		}
	}
	cout<<ct;
	return 0;
} 
