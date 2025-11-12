#include<bits/stdc++.h>
using namespace std;
long long n,m,k,h,g,d,s,e,w,a[500000],x,y,mid,ans,bj;
void dfs(long long qs,long long cs)
{
	ans=max(ans,cs);
	for(int i=qs;i<=n;i++)
	{
		mid=a[i];
		if(mid==k)
		{
			dfs(i+1,cs+1);
		}
		for(int j=i+1;j<=n;j++)
		{
			mid=mid^a[j];
			if(mid==k)
			{
				dfs(j+1,cs+1);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bj=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)bj=0;
	
	}
	if(bj==1&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
*/
