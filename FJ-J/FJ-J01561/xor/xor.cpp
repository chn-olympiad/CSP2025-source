#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,k,i,j,ans,now=1,num,a[N];
bool flag1=1,flag2=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1) flag1=0;
		if(a[i]!=1&&a[i]!=0) flag2=0;
	}
	if(flag1)
	{
		cout<<n/2;
		return 0;
	}
	if(flag2)
	{
		if(k==0)
		{
			for(i=1;i<=n;i++) 
			  if(a[i]==0) ans++;
				else if(i!=n&&a[i]==a[i+1]) ans++,i++;
			cout<<ans;
			return 0;
		}
		if(k==1)
		{
			for(i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans;
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		num=a[i];
		if(num==k) 
		{
			ans++,now=i+1;//cout<<i<<' ';
			continue;
		}
		for(j=i-1;j>=now;j--)
		{
			num^=a[j];
			if(num==k) 
			{
				ans++,now=i+1;//cout<<i<<' ';
				break; 
			}
		}
	}
	cout<<ans;
	return 0;
 }
//4 3
//2 1 0 3
//4 2
//2 1 0 3

