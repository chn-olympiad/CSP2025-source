#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
vector<int> ans;
int dfs(int x)
{
	if(x==cnt+1)
	{
		for(auto i:ans)
		{
			cout
		}
	}
}
*/

int cmp(int x,int y)
{
	return x>y;
}



string s; 
int a[1000010];
int cnt = 1;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=' '+s;
	for(int i=1;s[i];i++)
	{
		if(s[i]=='0')
		{
			a[cnt]=0; 
			cnt++;
		}
		if(s[i]=='1')
		{
			a[cnt]=1; 
			cnt++;
		}
		if(s[i]=='2')
		{
			a[cnt]=2; 
			cnt++;
		}
		if(s[i]=='3')
		{
			a[cnt]=3; 
			cnt++;
		}
		if(s[i]=='4')
		{
			a[cnt]=4; 
			cnt++;
		}
		if(s[i]=='5')
		{
			a[cnt]=5; 
			cnt++;
		}
		if(s[i]=='6')
		{
			a[cnt]=6; 
			cnt++;
		}
		if(s[i]=='7')
		{
			a[cnt]=7; 
			cnt++;
		}
		if(s[i]=='8')
		{
			a[cnt]=8; 
			cnt++;
		}
		if(s[i]=='9')
		{
			a[cnt]=9; 
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=1;i--)
	{
		cout<<a[i];
	}
	
	
	
}
