#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=2e5,M=5e6;
char s[3][M+5],t[3][M+5];
struct edge
{
	int l,r,nxt;
}e[N+5];
int lst[2*M+5],cnt;
void ad(int x,int y,int z)
{
//	printf("%d %d %d\n",x,y,z); 
	e[++cnt]={y,z,lst[x]};
	lst[x]=cnt;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s[1],s[2]);
		int ln=strlen(s[1]);
		int t1=0,t2=0;
		for(int j=0;j<ln;j++)
		{
			if(s[1][j]=='b')
			{
				t1=j;
			}
			if(s[2][j]=='b')
			{
				t2=j;
			}
		}
		int vl=t1-t2+M;
		ad(vl,min(t1,t2),min(ln-t1,ln-t2));
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s%s",t[1],t[2]);
		int ln=strlen(t[1]);
		int t1=0,t2=0;
		for(int j=0;j<ln;j++)
		{
			if(t[1][j]=='b')
			{
				t1=j;
			}
			if(t[2][j]=='b')
			{
				t2=j;
			}
		}
		int vl=t1-t2+M,s=0;
		for(int j=lst[vl];j;j=e[j].nxt)
		{
			if((min(t1,t2)>=e[j].l)&&(min(ln-t1,ln-t2)>=e[j].r))
			{
				s++;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
