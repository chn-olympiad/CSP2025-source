#include<bits/stdc++.h>

using namespace std;
//100pts
int t[15];
char x[1000005];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",x+1);
    int len = strlen(x+1);
    for(int i=1;i<=len;i++)
    {
        if(x[i] >= '0' && x[i] <= '9')
        {
            t[x[i] - '0']++;
        }
    }
    for(int i=10;i>=0;i--)
    {
        for(int j=1;j<=t[i];j++)
        {
            printf("%d",i);
        }
    }

    return 0;
}
