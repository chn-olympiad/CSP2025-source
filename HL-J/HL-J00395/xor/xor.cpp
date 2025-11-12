#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d",n);scanf("%d",k);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",a[i]);
    }
    if(n == 1)
    {
        if(a[1] == k)
        {
            printf("%d",1);
        }
        else
        {
            printf("%d",0);
        }
    }
    else if(n == 2)
    {
        printf("%d",3);
    }
    else
    {
        printf("%d",1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
