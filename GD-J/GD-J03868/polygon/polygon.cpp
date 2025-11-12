#include<iostream>
using namespace std;
int a[500],n,ans=0;
void dfs(int k,int len,int maxer,int sum)
{
	if(len>n) return;
	if(len>=3&&sum>maxer*2) ans++;
	for(int i=k+1;i<=n;i++)
		dfs(i,len+1,max(maxer,a[i]),sum+a[i]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
