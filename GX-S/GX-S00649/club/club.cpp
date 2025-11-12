#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a1=0,a2=0,a3=0,tj=0;
    cin>>t>>n;
    int a[n+1][n+1];
    while(t--)
    {
        int max=0,b[3]={0},xb;
        for(int i=0;i<n;i++)
        {
            for(int u=1;u<=3;u++)
            {
                cin>>a[u][i];
            }
        }

        for(int i=0;i<n;i++)
        {
            max=0;
            for(int u=1;u<=3;u++)
            {
                if(a[u][i]>max)
                {
                    max=a[u][i];
                }
            }
                tj+=max;




        }
            cout<<tj<<endl;

    }
    return 0;
}
