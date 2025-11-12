#include<bits/stdc++.h> 
using namespace std;
int n,a[5005],ans=0,o=1;
void dfs(int start,int sum,int m_x,int cnt)
{
	if(sum!=0&&m_x!=0&&sum>m_x*2) ans++;
	for(int i=start+1;i<=n;i++)
	{
		dfs(i,sum+a[i],max(m_x,a[i]),cnt++);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dfs(i,a[i],a[i],1);
	}
	cout<<ans;
	return 0;
}
