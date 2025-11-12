#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int p[1000010];
signed main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			p[++p[0]]=s[i]-'0';
	sort(p+1,p+p[0]+1,greater<int>());
	for(int i=1;i<=p[0];i++)
		cout<<p[i];
	return 0;
}
