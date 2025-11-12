#include<iostream>
using namespace std;
int n,a[5000],ans=0;
void dfs(int x,int y,int tt,int mx)
{
	if(tt>2*mx)
		ans=(ans+1)%998244353;
	if(x==n)
	{
		return;
	}
	for(int i=y+1;i<n;i++)
		dfs(x+1,i,tt+a[i],max(mx,a[i]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("poligon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dfs(0,-1,0,0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
