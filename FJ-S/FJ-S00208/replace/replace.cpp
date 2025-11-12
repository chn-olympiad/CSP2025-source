#include<algorithm>
#include<iostream>
#include<cstdio>
#define ll long long
#define Hoshino 520520520520ll
inline void write(ll x)
{
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline ll read()
{
	ll x=0;bool c=0;char a=getchar();
	for(;a<'0'||a>'9';a=getchar())c|=a==45;
	for(;a>='0'&&a<='9';a=getchar())x=(x<<3)+(x<<1)+(a^48);
	return c?-x:x;
}
#define R read()
using namespace std;

ll n,q;
string s[200002][3];

inline bool Check(string str,ll num,string target)
{
	for(ll i=0;i<str.length();++i)
	{
		bool flag=true;
		for(ll j=0;j<s[num][1].length();++j)if(s[num][1][j]!=str[i+j]){flag=false;break;}
		if(flag)
		{
			string str_=str;
			for(ll j=0;j<s[num][1].length();++j)str_[i+j]=s[num][2][j];
			if(str_==target)return true;
		}
	}
	return false;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	n=R,q=R;
	for(ll i=1;i<=n;++i)cin>>s[i][1]>>s[i][2];
	for(ll i=1;i<=q;++i)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll cnt=0;
		for(ll i=1;i<=n;++i)if(Check(s1,i,s2))++cnt;
		write(cnt),putchar(10);
	}
	return 0;
}
