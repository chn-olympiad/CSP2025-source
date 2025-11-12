#include<bits/stdc++.h>
using namespace std;
long long num=0;
const int N=1e4;
int n,a[N];
bool vis[N];
bool cmp(int a,int b)
{
	return a<b;
}
void dfs(int u,int sum,int maxx,int from)
{
	if(u<=0)
	{
		if(sum>2*maxx) num++;
		return;
	}
	for(int i=from;i<=n;i++)
	{
		if(!vis[i]){
			vis[i]=1;
			sum+=a[i];
			int temp=maxx;
			maxx=max(a[i],maxx);
			from++;
			dfs(u-1,sum,maxx,from);
			vis[i]=0;
			sum-=a[i];
			maxx=temp;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=i;i<=n;i++)
	{
		dfs(i,0,-1,1);
	}
	cout<<num%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 