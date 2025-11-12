#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,k; 
vector<long long> a;
void dfs(long long w,long long cnt,long long num)
{
	ans=max(ans,cnt);
	for(int i=w;i<n;i++)
	{
		if(num==-1) num=a[i];
		else num^=a[i]; 
		if(num==k) dfs(i+1,cnt+1,-1);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	dfs(0,0,-1);
	printf("%lld",ans);
	return 0;
}
