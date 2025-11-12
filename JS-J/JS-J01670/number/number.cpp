#include <bits/stdc++.h>
using namespace std;
string s;
int ha[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		if(s[i]>='0'&&s[i]<='9') ha[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=ha[i];j++) printf("%d",i);
	printf("\n");
	return 0;
}
