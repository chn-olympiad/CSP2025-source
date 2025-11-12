#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000005],cnt;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int t=s.size();
	for(int i=0;i<t;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
}
