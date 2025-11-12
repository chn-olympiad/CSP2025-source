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
const int N=1000;
const int Len=20000;
int n,q,Strlen[N+10];
char Str[N+10][2][Len+10],Qs1[Len+10],Qs2[Len+10];

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=Read(),q=Read();
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",Str[i][0]+1,Str[i][1]+1);
        Strlen[i]=strlen(Str[i][0]+1);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%s%s",Qs1+1,Qs2+1);
        int Ans=0;
        for(int j=1;j<=n;j++)
        {
            int QLen=strlen(Qs1+1);
            for(int l=1;l+Strlen[j]-1<=QLen;l++)
            {
                bool NFlag=true;
                for(int k=1;k<=Strlen[j];k++)
                    if(Str[j][0][k]!=Qs1[l+k-1]||Str[j][1][k]!=Qs2[l+k-1])
                    {
                        NFlag=false;
                        break;
                    }
                for(int k=1;k<=QLen;k++)
                {
                    if(l<=k&&k<=l+Strlen[j]-1)continue;
                    if(Qs1[k]!=Qs2[k])
                    {
                        NFlag=false;
                        break;
                    }
                }
                if(NFlag)Ans++;
            }
        }
        printf("%d\n",Ans);
    }
	return 0;
 } 