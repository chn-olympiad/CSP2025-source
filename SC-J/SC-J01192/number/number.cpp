#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string s;
char c[1000005];
int tot;
bool cmp(char a,char b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>s;
	int N=s.length();
	s=' '+s;
	for(int i=1;i<=N;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			tot++;
			c[tot]=s[i];
		}
	}
	sort(c+1,c+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		cout<<c[i];
	}
	return 0;
}