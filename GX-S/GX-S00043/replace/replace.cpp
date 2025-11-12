#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long 
using namespace std;
void read(ll &x)
{
	x=0;
	bool meg=0;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			meg=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	if(meg==1)
		x=-x;
	return ;
}
void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	if(x>=10) write(x/10),putchar(x%10+'0');
}
string readstring()
{
	string s="";
	char ch=' ';
	while(ch<'a'||ch>'z')
		ch=getchar();
	while(ch<='z'&&ch>='a')
	{
		s=s+ch;
		ch=getchar();
	}
	return s;
}
void writestring(string s)
{
	for(int i=0;s[i];i++)
		putchar(s[i]);
}
ll n,m;
string s1,s2,to[5000001];
int tos[5000001],totos=0;
int t[5000001][26],cnt;
int num;
void build()
{
	int p=0;
	for(int i=0;s1[i];i++)
	{
		int j=s1[i]-'a';
		if(t[p][j]==0) t[p][j]=++cnt;
		p=t[p][j];
	}
	tos[p]=++totos;
	to[tos[p]]=s2;
}
int query(int x)
{
	int p=0;
	int ans=0;
	for(int i=x;s1[i];i++)
	{
		int j=s1[i]-'a';
		
		
		
		
		if(t[p][j]==0&&tos[p]==0)// word gone head and no pipei 
			return ans;

		if(t[p][j]==0&&tos[p]!=0)//pipei to a word
		{
			string sb=to[tos[p]];
			bool well=0;
			for(int k=0;sb[k];k++)
			{
				if(sb[k]!=s2[x+k])
				{
					well=1;
					break;
				}
					
			}
			if(well==1)
				ans++;
		}
	}
	

	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		s1=readstring();
		s2=readstring();
		build();
	}
	for(int i=1;i<=m;i++)
	{
		s1=readstring();
		s2=readstring();
		for(int j=0;s1[j];j++)
			num+=query(j);
		write(num);
		putchar('\n');
	}
	return 0;
}

