#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,a[100001][4],r[4],h[100001],z[4][50001];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {

        cin>>n;
        bool l2=1,l3=1;
        for(int i=1;i<=n;i++)
        {
            ll zy=0,zz=0;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(a[i][j]>=zz)
                {
                    zz=a[i][j];
                    zy=j;
                }
            }
            ++r[zy];

            if(a[i][2])l2=0;
            if(a[i][3])l3=0;

        }
        ans=0;
        if(l2&&l3)
        {
            for(int i=1;i<=n;i++)
            {
                h[i]=a[i][1];
            }
           sort(h+1,h+1+n,cmp);
           for(int i=1;i<=n/2;i++)
           {
               ans+=h[i];
           }
        }
        else if(l3)
        {
            int w=1,f=2;
           if(r[2]>r[1])w=2,f=1;
           for(int i=1;i<=n;i++)
           {
               h[i]=a[i][f]-a[i][w];
               ans+=a[i][w];
           }
           sort(h+1,h+1+n,cmp);
           for(int i=1;i<=n/2;i++)
           {
               ans+=h[i];
           }
        }
        else{
              //  cout<<T<<endl;
            r[1]=0,r[2]=0,r[3]=0;
           for(int i=1;i<=n;i++)
           {
              // cout<<i<<':';
                ll zd=-1,x=0,si=0,sx=0,bh=0;
                for(int j=1;j<=3;j++)
                {
                 //       cout<<j<<',';
                    if(r[j]>=n/2)
                    {
                        int h1=j%3+1,h2=j%3+2;
                        if(r[h1]>=n/2)h1=0;
                        if(r[h2]>=n/2)h2=0;
                        for(int y=1;y<=r[j];y++)
                        {
                            int xx=z[j][y];
                            ll j1=a[i][j]-a[xx][j]+a[xx][h1],j2=a[i][j]-a[xx][j]+a[xx][h2];
                            ll jj,jh;
                            if(j1>j2) jj=j1,jh=h1;
                            else jj=j2,jh=h2;
                            if(jj>zd)
                            {
                                zd=jj;
                                x=xx;
                                si=j,sx=jh,bh=y;
                            }
                        }
                    }
                    else
                    {
                        if(a[i][j]>=zd)
                        {
                          zd=a[i][j],x=0,si=j,sx=0,bh=0 ;
                        }
                    }
                }
                if(x)
                {
                   // cout<<"bh "<<bh<<endl;
                    z[si][bh]=i;
                    z[sx][++r[sx]]=x;
                }
                else
                {
                   // cout<<si<<';';
                    z[si][++r[si]]=i;
                }
                    ans+=zd;
      //  cout<<zd<<' '<<ans<<' '<<r[1]<<' '<<r[2]<<' '<<r[3]<<endl;
           }
        }
   // cout<<T<<endl;
            cout<<ans<<"\n";
    }
    return 0;
}

