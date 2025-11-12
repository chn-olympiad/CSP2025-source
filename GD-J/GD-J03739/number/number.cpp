#include <bits/stdc++.h>
using namespace std;
string s;
char num[1000005];
bool cmp(const char &a,const char &b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0,j=0;i<(int)s.size();i++)
		if (s[i]>='0'&&s[i]<='9')
			num[j]=(char)s[i],j++;
	sort(num,num+(int)strlen(num),cmp);
	printf("%s",num);
	return 0;
}
