#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
ll a[1000001],tot;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]<='9'&&s[i]>='0')
			a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--)
		cout<<a[i];
	return 0;
}
