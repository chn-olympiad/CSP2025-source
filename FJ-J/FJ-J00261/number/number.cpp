#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
bool flag;
int n,cnt;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length(); s=" "+s;
	for(int i=1;i<=n;i++)
		if(s[i]<='9' && s[i]>='0') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		if(a[i]) printf("%d",a[i]),flag=1;
		else if(flag) printf("%d",a[i]);
	if(!flag) putchar('0');
	return 0;
}
