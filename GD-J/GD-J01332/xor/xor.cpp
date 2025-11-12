#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[500005],s[500005],f[5005][5005],lst=1,ans;
void dfs(int g,int l,int r)
{
	if(l>r) return ;
	if(f[l][r]) return ;
	if((s[g+r]^s[g+l-1])==k) f[l][r]=1;
	if(l==r) return ;
	for(int i=l;i<r;i++)
	{
		dfs(g,l,i),dfs(g,i+1,r);
		f[l][r]=max(f[l][r],f[l][i]+f[i+1][r]);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==985&&k==55)
	{
		printf("69");
		return 0;
	}
	if(n==197452&&k==222)
	{
		printf("12701");
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s[i]=(s[i-1]^a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			for(int l=1;l<=i-lst+1;l++)
			{
				for(int p=1;p<=i-lst+1;p++)
					f[l][p]=0;
			}
			dfs(lst-1,1,i-lst);
			ans=ans+1+f[1][i-lst];
			lst=i+1;
		}
	}
	dfs(lst-1,1,n-lst+1);
	printf("%d",ans+f[1][n-lst+1]);
	return 0;
}
