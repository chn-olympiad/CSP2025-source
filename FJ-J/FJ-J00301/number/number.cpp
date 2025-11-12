#include <bits/stdc++.h>
using namespace std;

int a[1000005];


bool cmp(int a,int b)
{
	return a>b;
}

string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt = 0;
	for(int i = 0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++)cout<<a[i];
	return 0;
}
//%%%艾伦·图灵之神%%%
//%%%冯·诺依曼之神%%%
//%%%%%%%%%%%%%%%%%%%%
//佑我此题100分 
