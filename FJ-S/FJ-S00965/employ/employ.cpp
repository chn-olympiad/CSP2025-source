#include<stdio.h>
#define P 998244353 
long long _jc(long long x)
{
	if(x==0)return 1;
	return(_jc(x-1)*x)%P;
}
int n,m,t=0;char s[505];
int main(void)
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d %s",&n,&m,s);
	if(m==n)
	{
		printf("0");
		return 0;
	}
	int d=0;
	for(int i=0;i<n;++i)
	{
		int r;
		scanf("%d",&r);
		if(r-d>0)++t;
		else ++d;
	}
	printf("%d",_jc(t));
	return 0;
}

