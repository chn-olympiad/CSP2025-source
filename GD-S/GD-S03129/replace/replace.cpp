#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		f=(ch=='-'?-1:f);
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void writech(ll x,char ch)
{
	write(x);
	putchar(ch);
}
const int MAXN=2e5+10,MAXS=5e6+10; 
int len[MAXN];
unsigned ll hsh[2][MAXN],nowhsh[2][MAXS],_131[MAXS];
const int base=131;
unsigned ll gethsh(int l,int r,int op)
{
	if(l==0)return nowhsh[op][r];
//	cout<<nowhsh[op][r]<<' '<<nowhsh[op][l-1]<<' '<<_131[r-l+1]<<'\n';
	return nowhsh[op][r]-nowhsh[op][l-1]*_131[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	_131[0]=1;
	for(int i=1;i<=5000000;++i)
	{
		_131[i]=_131[i-1]*base;
	}
	if(/*q==1||(n<=1000&&q<=1000)*/1)
	{
		for(int i=1;i<=n;++i)
		{
			string s1="",s2="";
			char ch=getchar();
			while(ch<'a'||ch>'z')ch=getchar();
			while(ch>='a'&&ch<='z')
			{
				s1+=ch;
				ch=getchar();
			}
			while(ch<'a'||ch>'z')ch=getchar();
			while(ch>='a'&&ch<='z')
			{
				s2+=ch;
				ch=getchar();
			}
			len[i]=s1.size();
			hsh[0][i]=s1[0]-'a'+1;
			hsh[1][i]=s2[0]-'a'+1;
			for(int j=1;j<len[i];++j)
			{
				hsh[0][i]=hsh[0][i]*base+s1[j]-'a'+1; 
				hsh[1][i]=hsh[1][i]*base+s2[j]-'a'+1;
			}
		}
		for(int i=1;i<=q;++i)
		{
			string t1="",t2="";
			char ch=getchar();
			while(ch<'a'||ch>'z')ch=getchar();
			while(ch>='a'&&ch<='z')
			{
				t1+=ch;
				ch=getchar();
			}
			while(ch<'a'||ch>'z')ch=getchar();
			while(ch>='a'&&ch<='z')
			{
				t2+=ch;
				ch=getchar();
			}
			if(t1.size()!=t2.size())
			{
				puts("0");
				continue;
			}
			int l=0,r=t1.size()-1;
			while(t1[l]==t2[l])l++;
			while(t1[r]==t2[r])r--;
			nowhsh[0][0]=t1[0]-'a'+1;
			nowhsh[1][0]=t2[0]-'a'+1;
			for(int j=1;j<t1.size();++j)
			{
				nowhsh[0][j]=nowhsh[0][j-1]*base+t1[j]-'a'+1;
				nowhsh[1][j]=nowhsh[1][j-1]*base+t2[j]-'a'+1;
			}
			int sz=t1.size();
			ll ans=0;
			for(int j=1;j<=n;++j)
			{
				for(int k=max(0,r-len[j]+1);k<=min(sz-len[j],l);++k)
				{
//					cout<<i<<' '<<j<<' '<<k<<' '<<len[j]<<' '<<hsh[0][j]<<' '<<gethsh(k,k+len[j]-1,0)<<' '<<hsh[1][j]<<' '<<gethsh(k,k+len[j]-1,1)<<'\n';
					if(hsh[0][j]==gethsh(k,k+len[j]-1,0)&&hsh[1][j]==gethsh(k,k+len[j]-1,1))ans++;
				}
			}
			writech(ans,'\n');
		}
	}
	return 0;
}

