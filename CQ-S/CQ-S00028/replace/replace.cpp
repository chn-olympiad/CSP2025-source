#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline string read_s()
{
	string res="";char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z') res+=c,c=getchar();
	return res;
}
int n,m;
#define ll unsigned long long
map<pair<ll,ll>,int>mp;
ll pw[50000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*233;
	n=read(),m=read();
	for(int i=1;i<=n;i++) 
	{
		string s[2];s[0]=read_s(),s[1]=read_s();
		ll hsh1=0,hsh2=0;
		for(int j=0;j<s[0].size();j++) hsh1=hsh1*233+s[0][j],hsh2=hsh2*233+s[1][j];
		++mp[{hsh1,hsh2}];
	}
	while(m--)
	{
		string t[2];t[0]=read_s(),t[1]=read_s();
		int ans=0,L=-1,R;
		for(int i=0;i<t[0].size();i++) 
			if(t[0][i]!=t[1][i])
			{
				if(L==-1) L=i;
				R=i;
			}
		for(int i=0;i<=L;i++)
		{
			ll hsh1=0,hsh2=0;
			for(int j=i;j<t[0].size();j++)
			{
				hsh1=hsh1*233+t[0][j],hsh2=hsh2*233+t[1][j];
				if(j>=R) ans+=mp[{hsh1,hsh2}];
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}
