#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct sp{
	int a,b,c;
}a[100010];
void dfs(int step,int x,int y,int z,int sum)
{
	if(step>n)
	{
		ans=max(ans,sum);
		return ;
	}
	if(x<n/2) dfs(step+1,x+1,y,z,sum+a[step].a);
	if(y<n/2) dfs(step+1,x,y+1,z,sum+a[step].b);
	if(z<n/2) dfs(step+1,x,y,z+1,sum+a[step].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		t--;
	}
	
	return 0;
}
