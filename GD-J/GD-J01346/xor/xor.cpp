#include<bits/stdc++.h>
using namespace std;
int n,k,maxn=-1e9;
int a[100005];
void js(int x,int ans,int sum)
{
	if(x==n+1)
	{
		maxn=max(maxn,sum);
		return;
	}
	if(sum+(n-x+1)<=maxn) return;
	if(ans==k) js(x+1,a[x+1],sum+1);
	else
	{
		js(x+1,ans^a[x+1],sum);
		js(x+1,a[x+1],sum);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	js(1,a[1],0);
	printf("%d",maxn);
	return 0;
}
