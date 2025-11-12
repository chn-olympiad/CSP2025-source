#include<bits/stdc++.h>
using namespace std;
int a[500020],pre[500020],b[500005],c[500005],ans,n,k;
int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    pre[i]=(pre[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((pre[j]^pre[i-1])==k)
			{
				b[i]=j;
				break;
			}
		}
		c[b[i]]=i;
	}
	sort(b+1,b+n+1);
	int j=1;
	for(int i=1;i<=n;i=i)
	{
		if(j>n)break;
		if(c[b[j]]>=i&&b[j]>0)
		{
			ans++;
			i=b[j]+1;
		}
		j++;
	}
	cout<<ans;
	return 0;	
} 
