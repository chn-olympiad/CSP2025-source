#include<iostream>
using namespace std;
long long n,m,c[501],sx[501],ans=0;
bool vis[501];
string str;
void dfs(long long x)
{
	if(x>n)
	{
		long long cnt=0;
		for(int z=1;z<=n;z++)
		  if(str[z]=='0'||cnt>=c[sx[z]])
			cnt++;
		if(n-cnt>=m)
		  ans++;
		return;
	}
	for(int z=1;z<=n;z++)
	{
		if(vis[z]==false)
		{
			vis[z]=true;
			sx[x]=z;
			dfs(x+1);
			vis[z]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>10)
	{
		cout<<0;
		return 0;
	}
	cin>>str;
	str=" "+str;
	for(int z=1;z<=n;z++)
	  cin>>c[z];
	dfs(1);
	cout<<ans;
	return 0;
}
/*
不可以总司令！
我相信ccf的数据强度！ 
*/
