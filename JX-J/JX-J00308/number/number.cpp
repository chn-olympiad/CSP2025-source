#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],tot=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
		if('0'<=s[i]&&s[i]<='9') a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--) cout<<a[i];
	return 0;
}
