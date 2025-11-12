#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	cin>>s;
	LL len=s.size();
	for(LL i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			s1=s1+s[i];
	sort(s1.begin(),s1.end(),cmp);
	len=s1.size();
	cout<<s1;
	return 0;
}
