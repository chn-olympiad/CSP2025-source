#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int t,n,sum,y;
    int a[101][5];
    int x[101];
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<3;k++)
            {
                scanf("%d",&a[j][k]);
            }
            for(int m=3;m>0;m++)
            {
                for(int h=0;h<m;h++)
                {
                    if(a[j][h]<=a[j][h+1])
                    {
                        y=a[j][h];
                        a[j][h+1]=a[j][h+1];
                        a[j][h+1]=y;
                    }
                }
            }
            for(int k=0;k<3;k++)
            {
                printf("%d ",a[j][k]);
            }
            cout<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
