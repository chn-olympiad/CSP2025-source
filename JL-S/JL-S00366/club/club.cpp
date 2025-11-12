#include <bits/stdc++.h>
using namespace std;
const long long N=1000000;
long long a1,a2,a3,p;
long long sum,maxn;
int t;
long long n,a[N][5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=3;j++)
            {

                cin>>a[i][j];
            }
        }
        p=n/2;
        for(int i=1;i<=n;i++)
        {
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])//13233333333333311111111111111111111111111111111
            {
                if(a[i][2]>a[i][3])
                {
                    if(a1<p)
                    {
                        a1++;
                        sum+=a[i][1];
                    }
                    else if(a2<p)
                    {

                        a2++;
                        sum+=a[i][2];
                    }
                    else{
                        a3++;
                        sum+=a[i][3];
                    }
                }
                else
                {
                    if(a1<p)
                    {

                        a1++;
                        sum+=a[i][1];
                    }
                    else if(a3<p)
                    {

                        a3++;
                        sum+=a[i][3];
                    }
                    else{
                        a2++;
                        sum+=a[i][2];
                    }

                }

            }
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])//2922uu2333333333333333333333333333333333333
            {
                if(a[i][1]>=a[i][2])
                {
                    if(a3<p)
                    {
                        a3++;
                        sum+=a[i][3];
                    }
                    else if(a1<p)
                    {

                        a1++;
                        sum+=a[i][1];
                    }
                    else{
                        a2++;
                        sum+=a[i][2];
                    }
                }
                else
                {
                    if(a3<p){


                        a3++;
                        sum+=a[i][3];
                    }
                    else if(a2<p)
                    {

                        a2++;
                        sum+=a[i][2];
                    }
                    else{
                        a1++;
                        sum+=a[i][1];
                    }}
                }

            else//33333333333333333333333333333333322222222222222222222222222222222222222222
                {
                if(a[i][1]>a[i][3])
                {
                    if(a2<p)
                    {

                        a2++;
                        sum+=a[i][2];
                    }
                    else if(a1<p)
                    {

                        a1++;
                        sum+=a[i][1];
                    }
                    else{
                        a3++;
                        sum+=a[i][3];
                    }
                }
                else
                {
                    if(a2<p)
                    {

                        a2++;
                        sum+=a[i][2];
                    }
                    else if(a3<p)
                    {

                        a2++;
                        sum+=a[i][3];
                    }
                    else{
                        a1++;
                        sum+=a[i][1];
                    }

                }
            }

        }
        cout<<sum<<endl;
    }
    return 0;
}
