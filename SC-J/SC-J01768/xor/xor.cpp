#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[N],num;
bool vis[N];
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
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[N];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 