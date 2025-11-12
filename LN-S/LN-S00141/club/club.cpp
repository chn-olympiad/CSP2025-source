#include<bits/stdc++.h>
using namespace std;
int F=205;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[F][5]={0},k[F]={0},p[5]={0},ans=0,w=0,r[F]={0},b[F/2][5]={0};
    cin>>t;
    while(t--)
    {
        n=0;
        a[F][5]={0};
        k[F]={0};
        p[4]={0};
        ans=0;
        w=0;
        r[F]={0};
        b[F/2][5]={0};
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) p[1]++,k[i]=1;
            if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3]) p[2]++,k[i]=2;
            if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]) p[3]++,k[i]=3;
        }
        if(p[1]>(n/2)) w=1;
        if(p[2]>(n/2)) w=2;
        if(p[3]>(n/2)) w=3;
        if(w==0)
        {
            for(int i=1;i<=n;i++)
            {
                ans+=a[i][k[i]];
            }
            cout<<ans;
            if(t!=0) cout<<endl;
            continue;
        }
        int j=1;
        for(int i=1;i<=n;i++)
        {
            if(k[i]==w)
            {
                if(w==1)
                {
                    if(a[i][1]-a[i][2]>=a[i][1]-a[i][3]) r[i]==2;
                    else r[i]==3;
                }
                if(w==2)
                {
                    if(a[i][2]-a[i][1]>=a[i][2]-a[i][3]) r[i]==1;
                    else r[i]==3;
                }
                if(w==3)
                {
                    if(a[i][3]-a[i][1]>=a[i][3]-a[i][2]) r[i]==1;
                    else r[i]==2;
                }
            }
        }

        while(1)
        {
            int mini=0x3f3f3f3f;
            int minn=0;
            for(int i=1;i<=n;i++)
            {
                if(k[i]==w)
                {
                    if(a[i][w]-a[i][r[i]]<=mini) {mini=a[i][w]-a[i][r[i]];minn=i;}
                }
            }
            k[minn]=r[minn];
            p[w]--;
            p[r[minn]]++;
            if(p[w]==n/2) break;
        }

        for(int i=1;i<=n;i++)
        {
            ans+=a[i][k[i]];
        }
        cout<<ans;
        if(t!=0)cout<<endl;
    }
    return 0;
}
