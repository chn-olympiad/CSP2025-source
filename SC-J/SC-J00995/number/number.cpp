#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int n=1e9;
string s,ss;
ll len,a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	s=' '+s;
	len=s.length()-1;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[s[i]-'0']	++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}