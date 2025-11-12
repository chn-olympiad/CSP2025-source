#include<bits/stdc++.h>
using namespace std;
int myseat[11451419],myseat1[11451419];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>myseat[i];
        if(i==1)
            cnt=myseat[i];
    }
    sort(myseat,myseat+(n*m));
    int ans=-1;
    for(int i=n*m,j=1;j<=n*m;i--,j++)
    {
        myseat1[j]=myseat[i];
        if(myseat1[j]==cnt)
            ans=j-1;
    }
    if(ans%n==0)
    {
        cout<<ans/n<<" ";
        if((ans/n)%2==0)
            cout<<1;
        else
            cout<<n;
    }
    else
    {
        cout<<ans/n+1<<" ";
        if((ans/n+1)%2==0)
        {
            cout<<m-(ans%n-1);
        }
        else
            cout<<ans%n;
    }

    return 0;
}
