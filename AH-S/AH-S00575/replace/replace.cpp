#include<cstdio>
#include<cstring>
#define N 200001
#define L 5200001
#define max(a,b) ((a)>(b)?(a):(b))
int n,q,l,r;
long long ans;
char *s[2][N],ss[2][L],t[2][L];
bool cmp(const char *s,const char *t)
{
	while(*s&&*t)
	{
		if(*s^*t)return false;
		++s,++t;
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	s[0][0]=ss[0],s[1][0]=ss[1];
	for(int i=0;i^n;++i)
	{
		scanf("%s%s",s[0][i],s[1][i]);
		s[0][i+1]=s[0][i]+strlen(s[0][i])+1,
		s[1][i+1]=s[1][i]+strlen(s[1][i])+1;
	}
//	for(int i=0;i^n;++i)
//		printf("DEBUG: %s %s\n",s[0][i],s[1][i]);
	while(q--)
	{
		ans=0;
		scanf("%s%s",t[0],t[1]);
		for(l=0;t[0][l]==t[1][l];++l);
		for(r=strlen(t[0]);t[0][r]==t[1][r];--r);
//		printf("DEBUG: %d %d\n",l+1,r+1);
		for(int i=0;i^n;++i)
		{
			int len=strlen(s[0][i]);
//			printf("\tDEBUG: %d %d\n",i,r-len+1);
			for(int j=max(r-len+1,0);j<=l;++j)
				if(cmp(s[0][i],t[0]+j)&&cmp(s[1][i],t[1]+j))
//				{
					++ans;
//					printf("\t\tDEBUG: %d %d\n",i,j);
//				}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
