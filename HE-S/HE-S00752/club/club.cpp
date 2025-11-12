#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n,T,a[20005][10],sum,tito;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>n;
        tito=n/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]+a[i+1][j]<a[i][j+1]+a[i+1][j])
                {
                    sum+=a[i][j+1];
                    tito--;
                }
                if(tito==1)
                {
                    sum+=max({a[i][j],a[i][j+1],a[i][j+2]});
                }
            }
        }
        cout<<sum<<"\n";
    }

    return 0;
}

