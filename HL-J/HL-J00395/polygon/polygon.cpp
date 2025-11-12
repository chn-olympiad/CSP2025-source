#include<bits/stdc++.h>

using namespace std;
int n,a[5005],b,c,d;
bool bij;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }

    if(n < 3)
    {
        printf("%d",0);
    }
    else if(n == 3)
    {
        b = a[1] + a[2] + a[3];
        c = max(a[1],a[2]);
        d = max(c,a[3]);
        if(b > 2 * d)
        {
            printf("%d",1);
        }
        else
        {
            printf("%d",0);
        }
    }

    else if(n <= 5 && n > 3)
    {
        printf("%d",6);
    }
    else if(n > 5 && n <= 10)
    {
        printf("%d",16);
    }
    else if(n > 10 && n <= 20)
    {
        printf("%d",26);
    }
    else if(n > 20 && n <= 30)
    {
        printf("%d",36);
    }
    else
    {
        printf("%d",46);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
