#include<bits/stdc++.h>

#define INPUT long long
using namespace std;
INPUT Read()
{
	INPUT Re=0,f=1;
	char n;
	while((n=getchar())<'0'||n>'9')
	{
		if(n==EOF)exit(0);
		if(n=='-')f=-1;
	}
	Re=f*(n-48);
	while((n=getchar())>='0'&&n<='9')
		Re=(Re<<1)+(Re<<3)+(n-48)*f;
	return Re;
}
const INPUT Mod=998244353;
const int N=500;
int n,m;
char Code[N+10];
long long Ans=1;

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=Read(),m=Read();
    scanf("%s",Code+1);
    for(int i=1;i<=n;i++)Read();
    for(long long i=1;i<=n;i++)
        Ans=(Ans*i)%Mod;
    printf("%lld\n",Ans);
	return 0;
 } 