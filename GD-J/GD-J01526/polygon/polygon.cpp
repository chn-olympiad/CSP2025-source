#include<bits/stdc++.h>
using namespace std;
int n,sum,a[5005];
void dfs(int m,int num,int mx,int now)
{
	if(m==0)
	{
		if(num>2*mx)sum++;
		return;
	}
	if(now>n)return;
	dfs(m-1,num+a[now],max(mx,a[now]),now+1);
	dfs(m,num,mx,now+1);
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
	for(int i=3;i<=n;i++)dfs(i,0,0,1);
	cout<<sum;
	return 0;
}
