#include<bits/stdc++.h>
using namespace std;
int n,m,vis[505],cnt,ans=0,s[50005],c[50005];
void dfs(int x)
{
	if(x==n+1)
	{
//		cout<<cnt<<endl;
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if((x-1-cnt)>=c[i]) 
			{
				vis[i]=1;
				dfs(x+1);
				vis[i]=0;
				continue;
			}
			vis[i]=1;
			if(s[x]) cnt++;
			dfs(x+1);
			vis[i]=0;
			if(s[x]) cnt--;
		}
	}
//	cout<<"H"<<endl;
}string st;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>st;
	for(int i=1;i<=n;i++) 
	{
		s[i]=st[i-1]-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
}
