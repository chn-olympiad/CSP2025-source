#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
char c[N];
int n=0;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c[++n]+=s[i];
		}
	}
	if(n==1)
	{
		cout<<c[n];
		return 0;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<c[i];
	return 0;
}
