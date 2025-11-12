#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();

string s;
int a[1000010]={},tot=0;

bool cmp(int x,int y)
{
	return x>y;
}

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='1'&&s[i]<='9')
			a[++tot]=s[i]-'0';
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++) printf("%lld",a[i]);
	return 0;
}

inline int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') 
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
