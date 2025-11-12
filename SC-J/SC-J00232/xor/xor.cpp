#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	} 
	if(k==0&&flag==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]|a[i+1]==k&&i+1<=n)
			{
				s++;
				i++;
			}
		}
	}
	if(k==0&&flag==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k) s++;
			else if(a[i]|a[i+1]==k&&i+1<=n)
			{
				s++;
				i++;
			}
		}
	}
	if(k==1&&flag==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k) s++;
			else if(a[i]|a[i+1]==k&&i+1<=n)
			{
				s++;
				i++;
			}
		}
	}
	cout<<s;
}