#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans,s[500010],id;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(k==1)
	{
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		cout<<ans;
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1)i++,ans++;
		}
		cout<<ans;
	}
	else 
	{
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=a[i]^a[i-1];
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)ans++,id=i+1;
			for(int j=id;j<=i;j++)if(a[i]^a[j-1]==k)ans++,id=i+1;
		}
		cout<<ans;
	}
	return 0;
}
