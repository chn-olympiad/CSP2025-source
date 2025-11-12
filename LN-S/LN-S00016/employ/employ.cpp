#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int t,n,sum,y;
    int a[101][3];
    int x[101];
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=3;k++)
            {
                scanf("%d",&a[j][k]);
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
