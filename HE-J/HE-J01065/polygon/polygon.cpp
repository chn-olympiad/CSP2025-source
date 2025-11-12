#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,on;
void dfs(int x)
{
	if(x>n)return ;
	if(x==n&&on==0)
	{
		ans++;
		on=1;
	}
	else 
	for(int i=x+1;i<=n;i++)
	{
		ans++;
		dfs(i+1);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==3)cout<<1;
	else {
	
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      dfs(j);
    cout<<ans%998244353;
 } 
	fclose(stdin);
	fclose(stdout);
 return 0; 
}
