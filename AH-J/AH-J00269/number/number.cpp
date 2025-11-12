#include <bits/stdc++.h>
using namespace std;
string s;
const int m=1e6+7;
char a[m];
int pos;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[pos++]=s[i];
	}
	sort(a,a+pos);
	for(int i=pos-1;i>=0;i--) cout<<a[i];
	return 0;
}
