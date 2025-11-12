#include<bits/stdc++.h>
using namespace std;
int  main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a=0,b=0;
    cin>>t>>n;
    int x[n][t];
    for(int i=0;i<=t;i++)
    {
        for(int m=1;m<=t;m++)
        {
            cin>>x[i][m];
            if(x[i][m]>x[i][m-1])
            {
                a=x[i][m];

            }
            else
            {
                a=x[i][m-1];

            }
            if(a<x[i][m-2])
            {

                a=x[i][m-2];
            }

        }
        b+=a;
    }
    cout<<b;
    return 0;

}
