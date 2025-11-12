#include <bits/stdc++.h>
using namespace std;

//unordered_map<string,bool> map;
const int N = 510,MODD = 998244353;
int n,m,a[N],c[N],num;
bool b[N];
string s;
bool i_check()
{
	int tmp = 0;
	for(int i=1;i<=n;i++)
	{
		if(s[i - 1] == '0' || tmp >= c[a[i]])
		{
			tmp ++ ;
		}
	}
	if(n - tmp < m) return false;
	return true;
}
void dfs(int id)
{
	if(id == n + 1)
	{
		if(i_check())
		{
			num = (num + 1) % MODD;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i] = true;
			a[id] = i;
			dfs(id + 1);
			b[i] = false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<num;
}