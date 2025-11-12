#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    long long n,k;
    scanf("%ld%ld",&n,&k);
    long long aruu[n+1]={0};
    long long arru[n+1]={0};
    for (long long i=1;i<=n;i++)
    {
        scanf("%ld",&aruu[i]);
    }
    long long sum=0;
    for (long long i=1;i<=n;i++)
    {
        for (long long j=i;j<=n;j++)
        {
            if (i==j)
            {
                if (aruu[j]==k)
                {
                    arru[i]++;
                    if (arru[i]<=1)
                        sum++;
                }
            }
            else
            {
                long long count0=aruu[i];
                for (long long m=i+1;m<=j;m++)
                {
                    count0^=aruu[m];
                }
                if (count0==k)
                {
                    bool flago=true;
                    for (long long y=i;y<=j;y++)
                    {
                        arru[y]++;
                        if (arru[y]>1)
                        {
                            flago=false;
                            break;
                        }
                    }
                    if (flago)
                        sum++;
                }
            }
        }
    }
    printf("%ld",sum);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
