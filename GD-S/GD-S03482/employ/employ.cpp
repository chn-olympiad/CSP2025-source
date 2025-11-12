#include<bits/stdc++.h>
using namespace std;
const int N=550;
int n,m,ok;
int c[N],cnt,total=1,away_;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin >> s;
	s = ' ' + s;
	for(int i = 1;i <= n;i++)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	
	for(int i = 1;i < s.size();i++)
	{
		if(s[1]=='1')
		{
			ok++;
		}
	}
	
	if(m == n && ok < n || ok < m)
	{
		printf("0");
		return 0;
	}
	
	for(int i = 1;i <= n;i++)
	{
		if(away_<n&&s[i]=='1') total*=(n-away_);
		away_+=c[i];
		c[i]=0;
	}
	
	printf("%d",total-1);
	return 0;
}
