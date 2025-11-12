#include<bits/stdc++.h>

using namespace std;

int n,k;
int a[500005];
int flga,flgb;
int tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flga=1;
			if(a[i]!=0)
			{
				flgb=1;
			}
		}
		else
		{
			tmp++;
		}
	}
	if(!flga)
	{
		if(k==1)
		{
			cout<<n;
			return 0;
		}
		if(k==0)
		{
			cout<<n/2;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(!flgb)
	{
		if(k==1)
		{
			cout<<tmp;
			return 0;
		}
		else if(k==0)
		{
			cout<<max((n-tmp),(tmp/2));
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	cout<<k;
}
