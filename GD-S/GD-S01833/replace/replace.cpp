#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
char *p1,*p2,buf[100000];
#define nc() getchar()
int read()
{
	int x=0;
	char ch=nc();
	for(;ch<48||ch>57;ch=nc());
	for(;ch>47&&ch<58;ch=nc()) x=(x<<3)+(x<<1)+ch-48;
	return x;
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}
string s[2][200010],ts[2];
int num[2000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		cin>>s[0][i]>>s[1][i];
	}
	for(;q;--q)
	{
		cin>>ts[0]>>ts[1];
		num[0]=(ts[0][0]!=ts[1][0])?1:0;
		int m=ts[0].size();
		for(int i=1;i<m;++i)
		{
			num[i]=num[i-1]+((ts[0][i]!=ts[1][i])?1:0);
		}
		int cnt=0;
		for(int k=1;k<=n;++k)
		{
			int tn=m-s[0][k].size();
			for(int i=0;i<=tn;++i)
			{
				bool flag=0;
				if(num[i-1])
				{
					break;
				}
				if(num[m-1]-num[i+s[0][k].size()-1]) continue;
				for(int j=0;j<s[0][k].size();++j)
				{
					if(s[0][k][j]!=ts[0][i+j]||s[1][k][j]!=ts[1][i+j])
					{
						flag=1;
						break;
					}
				}
				if(!flag) ++cnt;
			}
		}
		write(cnt),putchar('\n');
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*//*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
