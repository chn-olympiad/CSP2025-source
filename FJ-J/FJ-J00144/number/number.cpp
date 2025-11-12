#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll top;
char c[100005];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll sl=s.length();
	for(int i=0;i<=sl;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			c[++top]=s[i];
		}
	}
	sort(c+1,c+1+top,cmp);
	for(int i=1;i<=top;i++)
	{
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
