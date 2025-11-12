#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,x;
string d,f;
map<string,bool>mp;
void dfs(int h,int sum,int mx,int z,string s)
{
	if(z>=3&&mx*2<sum)
	{
		if(!mp[s])ans++;
		mp[s]=1;
	}
	if(h>n)return;
	dfs(h+1,sum,mx,z,s);
	x=h;
	while(x)
	{
		f=' '+char(x%10);
		d=f+d;
		x/=10;
	}
	dfs(h+1,sum+a[h],max(mx,a[h]),z+1,s+d);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0,"");
	cout<<ans;
}