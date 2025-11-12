#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],ans,vis[N];
void dfs(int,int x,int sum,int);
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>2*(max(max(a[1],a[2]),a[3])))cout<<1;
		else cout<<0;
		return 0;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=2;j<=n;j++)
//		{
//			int sum=0,maxn=INT_MIN;
//			if(i+j>n)continue;
//			for(int k=i;k<=i+j;k++)
//			{
//				sum+=a[k];
//				maxn=max(a[k],maxn);
//			}
//			if(sum>2*maxn)
//			{
//				ans++;
//				for(int k=i;k<=i+j;k++)
//				{
//					cout<<a[k]<<' ';
//				}
//				cout<<endl;
//			}
//		}
//	}
	dfs(1,0,0,INT_MIN);
	cout<<ans%998244353;
	return 0;
}
void dfs(int id,int x,int sum,int maxn)
{
	if(x>=3&&sum>maxn*2)ans++;
	ans%=998244353;
	for(int i=id;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		dfs(i,x+1,sum+a[i],max(maxn,a[i]));
		vis[i]=0;
	}
}
