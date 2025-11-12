#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[11],d,maxd = 0;
char b[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&b);
    int c = sizeof(b);
    for(int i = 0;i < c;i++)
    {
        d = b[i] - '0';
        if(d >= 0 && d <= 9)
        {
            a[d]++;
            if(d > maxd)
            {
                maxd = d;
            }
        }

    }
    if(maxd == 0)
    {
        printf("%d",0);
    }
    else
    {
        for(int j = maxd;j >= 0;j--)
        {
            for(int i = 0;i < a[j];i++)
            {
                printf("%d",j);
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
