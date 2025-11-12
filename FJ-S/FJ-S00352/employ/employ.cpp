#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int n,m,c[510],employ[510],ans;
string s;
void dfs(int right,int wrong,int num)
{
	if(right == m)
	{
		ans++;
		return;
	}
	if(num == n&&right != m) return;
	for(int i = 1;i <= n;i++)
	{
		if(employ[i]) continue;
		if(c[i] < wrong) continue;
		employ[i] = 1;
		if(s[num] == '0') dfs(right,wrong+1,num+1);
		else dfs(right+1,wrong,num+1);
		employ[i] = 0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i <= m;i++)
		cin>>c[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}


