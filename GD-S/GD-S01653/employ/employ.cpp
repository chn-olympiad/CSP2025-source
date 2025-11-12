#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],p[505],ksz[505],hsk[505],nx,sum,ed;
string st;
void dps(int pe[505],int da)
{
	int pd=1;
	for(int i=1;i<=n;i++)
	{
		if(pe[i]==0&&p[i]>a[da])
		{
			pe[i]=1,pd=0;
			dps(pe,da+1);
			pe[i]=0;
		}
	}
	if(pd==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(pe[i]==1) ans++;
		}
		if(ans>=m)
		{
			sum++;
		} 
	}
	return;
}
int main()
{
	cin>>n>>m>>st;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		a[i]=1-(st[i-1]-'0')+a[i-1];
	}
	dps(ksz,1);
	cout<<sum%998244353;
	return 0;
} 
