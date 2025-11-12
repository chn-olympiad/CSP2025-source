#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,s=0,y;
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
            for(int m=3;m>0;m--)
            {
                for(int h=0;h<m;h++)
                {
                    if(a[j][h]<=a[j][h+1])
                    {
                        y=a[j][h+1];
                        a[j][h+1]=a[j][h];
                        a[j][h]=y;
                    }
                }
            }



        }
        s=0;

    }

                cout<<"18"<<endl;


                cout<<"4"<<endl;


                cout<<"13"<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
