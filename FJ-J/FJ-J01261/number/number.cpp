#include <bits/stdc++.h>
using namespace std;
char c[1000005];
string s;
int len;
bool cmp(char a,char b)
{
	if (a>b) return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++) if (s[i]>='0'&&s[i]<='9') c[++len]=s[i];
	sort(c+1,c+len+1,cmp);
	for (int i=1;i<=len;i++) cout<<c[i];
	return 0;
}