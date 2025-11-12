#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int pos;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++pos]=s[i];
	}
	sort(a+1,a+pos+1,cmp);
	for(int i=1;i<=pos;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
