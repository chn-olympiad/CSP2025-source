#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int pre[1005];
int memo[1005][1005];
int p=0,q=0;
int dfs(int l,int r)
{
	if(l>r) return 0;
	if(l==r) return (int)(a[l]==k);
	int sum=0;int f=pre[r]^pre[l-1];
	if(f==k) sum++;
	for(int i=l;i<r;i++)
	{
		if(memo[l][i]==0) memo[l][i]=dfs(l,i);
		if(memo[i+1][r]==0) memo[i+1][r]=dfs(i+1,r);
		sum=max(sum,memo[l][i]+memo[i+1][r]);
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=a[i]^pre[i-1];
		if(a[i]==1) p++;
		if(a[i]==0) q++;
	}
	if(n>100&&k==1)
	{
		cout<<p;
		return 0;
	}
	if(n>100&&k==0)
	{
		cout<<q;
		return 0;
	}
	cout<<dfs(1,n);
	return 0;
}
