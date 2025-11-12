#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[5];
int ans;
int a[100005],b[100005],c[100005];
int f[205][205][205];
int T;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=0;i<=n/2;i++)
        {
            for(int j=0;j<=n/2;j++)
            {
                for(int k=0;k<=min(n/2,n-i-j);k++)
                {

                    int t=i+j+k;
                    if(t!=n)
                    {
                        t++;
                        if(i!=n/2)
                        {
                            f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[t]);
                        }
                        if(j!=n/2)
                        {
                            f[i][j+1][k]=max(f[i][j+1][k],f[i][j][k]+b[t]);
                        }
                        if(k!=n/2)
                        {
                            f[i][j][k+1]=max(f[i][j][k+1],f[i][j][k]+c[t]);
                        }
                    }
                }
            }
        }
        for(int i=0;i<=n/2;i++)
        {
            for(int j=0;j<=n/2;j++)
            {
                for(int k=0;k<=n/2;k++)
                {
                    ans=max(ans,f[i][j][k]);
                    //cout<<f[i][j][k]<<' ';
                    f[i][j][k]=0;
                }
                //cout<<endl;
            }
            //cout<<endl;
        }
        cout<<ans<<'\n';
        ans=0;

    }
    return 0;
}
