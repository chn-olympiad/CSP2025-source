#include<bits/stdc++.h>
using namespace std;

int n;
int a[5010];
bool used[5010];
long long ans;
bool path[5010];
void dfs(int now,int nowmax,int nowsum)
{
	if(now==n+1)
	{
		if(nowsum>2*nowmax)
		{
			ans++;
			ans%=988244353;
//			for(int i=1;i<now;i++)
//			{
//				if(path[i]==1)
//				{
//					cout<<a[i]<<" ";
//				}
//			}
//			cout<<endl;
		}
		return ;
	}
	//path[now]=1;
	dfs(now+1,max(nowmax,a[now]),nowsum+a[now]);
	//path[now]=0;
	
	dfs(now+1,nowmax,nowsum);
	
}
int main()
{
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,-1,0);
	cout<<ans-1;
}
