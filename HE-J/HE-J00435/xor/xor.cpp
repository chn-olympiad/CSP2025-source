#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500005],b[500005],d[500005],g[500005],h[500005];
int dp(int f[],int m)
{
	if(m==0)
	return 0;
	if(m==1)
	{
		if(f[1]==1)
		return 1;
		else
		return 0;
	}
	else
	{
		int w=0;
		for(int i=1;i<=(m+1)/2;i++)
		{
			if(f[i]>=(m+1)/2)
			{
				for(int j=1;j<i;j++)
				{
					g[j]=f[j];
				}
				for(int j=f[i]+1;j<=m;j++)
				{
					h[j-f[i]]=f[j];
				}
				w=max(w,dp(g,i-1)+1+dp(h,m-f[i]));
			}
		}
		return w;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{cin>>a[i];
	b[i]=b[i-1]^a[i];
	}
	for(int i=0;i<n;i++)
	{int c=b[i]^k;
	for(int j=i+1;j<=n;j++)
	{if(c==b[j]){d[i+1]=j;
	break;
	}
	}
	}
	cout<<dp(d,n);
	return 0;
}
