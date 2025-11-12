#include<bits/stdc++.h>
using namespace std;
int t,n,zd[100005][5],ans;
int sf[5];
void f(int x,int y)
{
    if(x==n)
    {
    for(int i=1;i<=3;i++)
        {
            if(sf[i]<n/2)
            {
                y+=zd[x][i];
                ans=max(y,ans);
              y-=zd[x][i];

            }
        }

    }
    for(int i=1;i<=3;i++)
    {

        if(sf[i]<n/2)
        {
            y+=zd[x][i];
            sf[i]++;
            f(x+1,y);
            y-=zd[x][i];
            sf[i]--;
        }
    }

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>zd[i][1]>>zd[i][2]>>zd[i][3];

        }
        f(1,0);
        cout<<ans<<"\n";
        for(int i=1;i<=3;i++)
        {
            sf[i]=0;
        }
        ans=0;
    }
    return 0;
}
