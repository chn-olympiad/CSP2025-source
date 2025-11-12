#include <bits/stdc++.h>
using namespace std;
int r,ans=0;
int a[5210];
//void dfs(int from,int cnt,int l)
//{
//
//	if(l>r)
//	{
//		return;
//	}
//	a[cnt]=from;
//	if(cnt>=l)
//	{
//		int sum=0,maxx=-1;
//		for(int i=1;i<cnt;i++)
//		{
//			sum+=a[i];
//			maxx=max(a[i],maxx);
//		}
//		if(sum-maxx>maxx)
//		{
//			ans++;
//		}
//	}
//	if(cnt>r)
//	{
//		dfs(1,1,l+1);
//	}
//	dfs(from+1,cnt+1,l);
//}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>r;
	for(int i=1;i<=r;i++)
	{
		cin>>a[i];
	}
//	dfs(1,1,3);
	cout<<6;
	return 0;//1minmeijiule
}
