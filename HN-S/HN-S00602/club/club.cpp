#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int s[N][4];
int num[4];
bool vis[N][3];
int ans,t=-999;
void dfs(int i)
{
	if(i>n) 
	{
		t=max(t,ans);
		return;
	}
	for(int j=1;j<=3;j++)
	{
		if(vis[i][j]==0&&num[j]<n/2) 
		{
			vis[i][j]=1;
			num[j]++;
			ans+=s[i][j];
			dfs(i+1);
			vis[i][j]=0;
			num[j]--;
			ans-=s[i][j];
		}
	}
	return;
}
signed main()
{  
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
		t=-999;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			
		}
		dfs(1);
		cout<<t<<endl;
	}
}
