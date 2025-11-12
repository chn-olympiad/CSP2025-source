#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool ch[105];
int mingc = 0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,n,m,a1,c,r;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i = 0;i < n*m;i++)
    {
        scanf("%d",&a);
        if(i == 0)
        {
            a1 = a;
        }
        ch[a] = 1;

    }
    for(int i = 100;i > a1;i++)
    {
        if(ch[i] == 1)
        {
            mingc++;
        }

    }
    mingc++;

    c = mingc / m;
    r = mingc % n;

    if(r > 0)
    {
        c += 1;
    }
    if(c % 2 == 1)
    {
        if(r == 0)
        {
            r = n;
        }
    }
    else
    {
        if(r == 0)
        {
            r = 1;
        }
        else
        {
           r = n + 1 - r;
        }
    }
    printf("%d ",c);
    printf("%d",r);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
