#include<iostream>
#include<algorithm>
using namespace std;
string str;
const int MAXN = 1000005;
int s[MAXN];
int s_i=1;
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if('0'<=str[i] && str[i]<='9')
		{
			s[s_i] = str[i]-'0';
			s_i++;
		}
	}
	sort(s+1,s+s_i,cmp);
	for(int i=1;i<s_i;i++)
	{
		cout<<s[i];
	}
	return 0;
} 