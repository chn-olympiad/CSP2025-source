#include<bits/stdc++.h>
using namespace std;
int t=0,n=0,ans=0;
int x=0,y=0,z=0;
int a[100005][15];
void dfs(int cur=0,int sum=0)
{	
	
	if(cur>=n)
	{
		ans=max(ans,sum);
		return ;
	}
	
	dfs(cur+1,sum+a[cur][1]);
	dfs(cur+1,sum+a[cur][2]);
	dfs(cur+1,sum+a[cur][3]);
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	


	return 0;
}
