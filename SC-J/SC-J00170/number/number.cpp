#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int a[1000010];
bool cmp(int x,int y)
{
	return x>y;
}
int main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			++n;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)putchar(a[i]+'0');
	fclose(stdin);
	fclose(stdout);
	return 0;
}