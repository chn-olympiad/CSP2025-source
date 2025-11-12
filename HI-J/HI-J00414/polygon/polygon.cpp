#include<bits/stdc++.h>
using namespace std;
bool vis[5005];
long long ans=0,n;
long long a[5005];
//x是下标，y是和，max1是方案中的最大值 
void dfs(long long x,long long y,long long max1)
{
	if(y>max1*2)
	{
		ans++;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			vis[i]=true;
			dfs(i,y+a[i],a[i]);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

