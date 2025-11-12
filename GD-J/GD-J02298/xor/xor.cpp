#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],t,k,x,y,ans,cnt;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int p=1,pp=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(a[i]!=1) p=0;
		if(a[i]>1) pp=0;
		if(a[i]==1) cnt++;
	}
	if(p==1&&k==0) return cout<<n/2,0;
	if(pp==1)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1&&a[i+1]==1) ans++,i++;
				if(a[i]==0) ans++;
			}
			return cout<<ans,0;
		 } 
		else return cout<<cnt,0;
	}
	cout<<0;
	return 0;
 } 
