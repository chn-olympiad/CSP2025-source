#include<iostream>
using namespace std;
int n,a[5005],ans=0;
void dfs(long long x,int y,int z,int k)
{
	if(z>=3&&x>y*2)
	{
//		cout<<x<<" "<<y<<endl;
		ans++;
	}
	for(int i=k+1;i<=n;i++)
	{
		dfs(x+a[i],max(y,a[i]),z+1,i);
	}
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
	for(int i=1;i<=n;i++)
	{
		dfs(a[i],a[i],1,i);
	}
	cout<<ans<<endl;
	return 0;
}
