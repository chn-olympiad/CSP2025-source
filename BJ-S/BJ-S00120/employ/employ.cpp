#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MOD=998244353;
//const int NR=
void Add(int &i,int j) {i+=j;i>=MOD?i-=MOD:1;}
const int NR=1e5+5;
int c[NR];
char s[NR];
int f[2][20][(1<<18)+5];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);	
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",c+i);
	}
	int ct=0;
	int p=0,q=1;
	f[q][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		swap(p,q);
		memset(f[q],0,sizeof(f[q]));
		for(int o=0;o<i;++o)
		{
			for(int j=0;j<(1<<n);++j)
			{
				if(!f[p][o][j]) continue;
				for(int k=1;k<=n;++k) if(!(j>>k-1&1))
				{
					if(c[k]<=o||s[i]=='0') Add(f[q][o+1][(j|(1<<k-1))],f[p][o][j]);
					else Add(f[q][o][j|(1<<k-1)],f[p][o][j]);
				}
			}
		}
	}
	int ans=0;
	for(int o=n-m;o>=0;--o) Add(ans,f[q][o][(1<<n)-1]);
	printf("%d\n",ans);
	return 0;
}