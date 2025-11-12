#include<bits/stdc++.h>
using namespace std;

int t,n;
int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int K=1;K<=t;K++)
    {
        int a[100005][3]={0},sum=0,teshu[100005]={0},num=0;

        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<=2;j++)
            {
                scanf("%d",&a[i][j]);

            }
            teshu[i]=a[i][0];

        }

        sort(teshu,teshu+n+1);


        for(int i=n;i>=1;i--){

            if(num<n/2)
            {
                sum+=teshu[i];
                num++;

            }




        }
        printf("%d\n",sum);


    }
    return 0;

}
