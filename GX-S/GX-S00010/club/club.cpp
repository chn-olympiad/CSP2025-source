#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int g;
    cin>>g;
    int f[g]={0};
    for(int gh=0;gh<g;gh++)
    {
        int n,x[4]={0},s=0,n1;
        cin>>n;
        n1=n/2;
        int a[n][3];
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3-j-1;k++)
                {
                    if(a[i][k]<a[i][k+1])
                    {
                        swap(a[i][k],a[i][k+1]);
                    }
                }
            }
        }

        f[gh]=a[0][0]+a[1][0];
    }
    for(int gh=0;gh<g;gh++)
    {

        cout<<f[gh]<<endl;
    }
    return 0;
}
