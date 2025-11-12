#include <bits/stdc++.h>

using namespace std;

int n,k,r=0;

bool flag;

int a[500005],f[2500000];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
    {
        int j=i,p=a[i];
        if(p==k)
        {
            f[i]=f[i-1]+1;
            r=i;
            continue;
        }
        j--;
        for(;j>r;j--)
        {
            p=p^a[j];
            if(p==k)
            {
                r=i;
                flag=1;
                break;
            }
        }
        if(flag)f[i]=f[j-1]+1;
        else f[i]=f[i-1];
        flag=0;
    }
    printf("%d",f[n]);
}
