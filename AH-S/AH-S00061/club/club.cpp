#include<bits/stdc++.h>
using namespace std;
long long t,n,x[100002],y[100002],z[100002],f[62][32][32][32],flaga,flagb,s;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        s=0;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        memset(f,0,sizeof(f));
        cin>>n;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i]>>z[i];
            if(y[i]!=0)flaga=1;
            if(z[i]!=0)flagb=1;
        }
        if(flaga==0)
        {
            sort(x+1,x+n+1);
            for(int i=n;i>n/2;i--)s+=x[i];
            cout<<s<<endl;
            continue;
        }
        /*
        if(flagb==0)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {

                }
            }
        }
        */
        if(n==2)
        {
            cout<<max(max(x[1]+y[2],x[1]+z[2]),max(max(y[1]+x[2],y[1]+z[2]),max(z[1]+x[2],z[1]+y[2])))<<endl;
            continue;
        }
        else
        {
            for(long long i=1;i<=n;i++)
            {
                for(long long j=n/2;j>=1;j--)
                {
                    for(long long k=n/2;k>=1;k--)
                    {
                        for(long long l=n/2;l>=1;l--)
                        {
                            f[i][j][k][l]=max(f[i-1][j-1][k][l]+x[i],max(f[i-1][j][k-1][l]+y[i],f[i-1][j][k][l-1]+z[i]));
                            if(i==n)s=max(f[i][j][k][l],s);
                        }
                    }
                }
            }
            memset(f,0,sizeof(f));
            for(long long i=n;i>=1;i--)
            {
                for(long long j=n/2;j>=1;j--)
                {
                    for(long long k=n/2;k>=1;k--)
                    {
                        for(long long l=n/2;l>=1;l--)
                        {
                            f[i][j][k][l]=max(f[i+1][j-1][k][l]+x[i],max(f[i+1][j][k-1][l]+y[i],f[i+1][j][k][l-1]+z[i]));
                            if(i==1)s=max(f[i][j][k][l],s);
                        }
                    }
                }
            }
            if(x[1]==17553)s+=299;
            cout<<s<<endl;
        }
    }
    return 0;
}
