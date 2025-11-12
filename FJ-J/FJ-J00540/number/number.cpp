#include<bits/stdc++.h>
#define int long long
using namespace std;
int num,tmp;
string s;
char a[1000010];
bool cmp(char a,char b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)(s.size());i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++num]=s[i];
		}
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		cout<<a[i];
	}
	return 0;
}
