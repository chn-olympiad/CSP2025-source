#include <bits/stdc++.h>
using namespace std;
const int TOP=1e5+5;
int T;
int n;//¶áÉÙÑ§Éú
int a[TOP][5];
int ans;
void dfs(int now,int num1,int num2,int num3,int zong)
{
	if(now>n)
	{
		ans=max(ans,zong);
		return ;
	}
	if(num1<n/2)
		dfs(now+1,num1+1,num2,num3,zong+a[now][1]);
	if(num2<n/2)
		dfs(now+1,num1,num2+1,num3,zong+a[now][2]);
	if(num3<n/2)
		dfs(now+1,num1,num2,num3+1,zong+a[now][3]);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
