#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define MINN -21474836
#define inf 2147483647
using namespace std;
int n;
namespace pts2
{
    int a[4],b[4],ans[12];
    int k=1;
    bool vis[4];
    void mian()
    {

        cin>>a[1]>>a[2]>>a[3];
        cin>>b[1]>>b[2]>>b[3];
        for(int i=1; i<=3; i++)
        {
            for(int j=1; j<=3; j++)
            {
                if(i!=j)
                    ans[k++]=a[i]+b[j];
            }
        }
        int maxn=MINN;
        for(int i=1; i<k; i++)
        {
            if(ans[i]>maxn) maxn=ans[i];
        }
        cout<<maxn<<'\n';
        return ;
    }
}

namespace pts4
{
    int a[4], b[4], c[4], d[4];
    int ans;
    bool ok(int a1, int a2, int a3, int a4)
    {
        if(a1==a2&&a2==a3) return false;
        if(a1==a2&&a2==a4) return false;
        if(a1==a3&&a3==a4) return false;
        if(a2==a3&&a3==a4) return false;
        return true;
    }
    void mian()
    {
        for(int i=1; i<=3; i++) cin>>a[i];
        for(int i=1; i<=3; i++) cin>>b[i];
        for(int i=1; i<=3; i++) cin>>c[i];
        for(int i=1; i<=3; i++) cin>>d[i];
        ans=MINN;
        for(int i=1; i<=3; i++)
        {
            for(int j=1; j<=3; j++)
            {
                for(int k=1; k<=3; k++)
                {
                    for(int l=1; l<=3; l++)
                    {
                        if(ok(i,j,k,l))
                            ans=max(ans, a[i]+b[j]+c[k]+d[l]);
                    }

                }
            }
        }
        cout << ans << endl;
    }
}
namespace pts30
{
    int a[209][4];
    ll ans;
    ll f[209][105][105][105];
    ll maxll(ll x1, ll x3, ll x4)
    {
        return max(x1, max(x3, x4));
    }
    void print(ll x)
    {
        if(x<0) cout << "-inf"<< " ";
        else cout << x<< " ";
    }
    void mian()
    {
        for(int i=1; i<=n; i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }

        for(int i=1; i<=3; i++)
        {
            f[1][1][0][0]=a[1][1];
            f[1][0][1][0]=a[1][2];
            f[1][0][0][1]=a[1][3];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n/2; j++)
            {
                for(int k=1; k<=n/2; k++)
                {
                    for(int l=1; l<=n/2; l++)
                    {
                        f[i][j][k][l]=-inf;
                    }
                }
            }
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<=n/2; j++)
            {
                for(int k=0; k<=n/2; k++)
                {
                    for(int l=0; l<=n/2; l++)
                    {
                        if(j+k+l==i)
                        {
                            int f1=0, f2=0, f3=0;
                            if(j>0)
                                f1=f[i-1][j-1][k][l]+a[i][1];
                            else
                                f1=-inf;
                            if(k>0)
                                f2=f[i-1][j][k-1][l]+a[i][2];
                            else
                                f2=-inf;
                            if(l>0)
                                f3=f[i-1][j][k][l-1]+a[i][3];
                            else
                                f3=-inf;

                                f[i][j][k][l]=maxll(f1,f2,f3
                                              );

                            /*
                            f[i][j][k][l]=maxll(
                                f[i-1][j-1][k][l]+a[i][1],
                                f[i-1][j][k-1][l]+a[i][2],
                                f[i-1][j][k][l-1]+a[i][3]
                                              );
                            */
                        }
                    }
                }
            }
        }

        ans=MINN;
        int maxi=MINN, maxj=MINN, maxl=MINN;
        for(int i=0; i<=n>>1; i++)
        {
            for(int j=0; j<=n>>1; j++)
            {
                for(int l=0; l<=n>>1; l++)
                {

                    if(f[n][i][j][l]>ans && i+j+l==n)
                    {
                        ans=f[n][i][j][l];
                        maxi=i;
                        maxj=j;
                        maxl=l;
                    }

                }
               // cout <<endl;
              //  ans=max(ans, f[n][i][j][n-i-j]);

            }
        }
        cout << ans << endl;
        return ;
    }
}

namespace pts200
{
    int a[209][4];
    ll ans;
    ll f[2][109][109][109];
    ll maxll(ll x1, ll x3, ll x4)
    {
        return max(x1, max(x3, x4));
    }
    void mian()
    {
        for(int i=1; i<=n; i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }

        for(int i=1; i<=3; i++)
        {
            f[1][1][0][0]=a[1][1];
            f[1][0][1][0]=a[1][2];
            f[1][0][0][1]=a[1][3];
        }
        for(int i=0; i<=1; i++)
        {
            for(int j=1; j<=n/2; j++)
            {
                for(int k=1; k<=n/2; k++)
                {
                    for(int l=1; l<=n/2; l++)
                    {
                        f[i][j][k][l]=-inf;
                    }

                }
            }
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<=n/2; j++)
            {
                for(int k=0; k<=n/2; k++)
                {
                    /*
                    for(int l=0; l<=n/2; l++)
                    {
                        if(j+k+l!=i) continue;
                    */
                        int l=i-j-k;
                        int f1=0, f2=0, f3=0;
                        if(j>0)
                            f1=f[!(i%2)][j-1][k][l]+a[i][1];
                        else
                            f1=-inf;
                        if(k>0)
                            f2=f[!(i%2)][j][k-1][l]+a[i][2];
                        else
                            f2=-inf;
                        if(l>0)
                            f3=f[!(i%2)][j][k][l-1]+a[i][3];
                        else
                            f3=-inf;
                        f[i%2][j][k][l]=maxll(f1,f2,f3);
                    }

                }
            }


        ans=MINN;
        int maxi=MINN, maxj=MINN, maxl=MINN;
        for(int i=0; i<=n>>1; i++)
        {
            for(int j=0; j<=n>>1; j++)
            {
                int l=n-i-j;
                if(f[n%2][i][j][l]>ans && i+j+l==n)
                {
                    ans=f[n%2][i][j][l];
                }

               // cout <<endl;
              //  ans=max(ans, f[n][i][j][n-i-j]);

            }
        }
        cout << ans << endl;
        return ;
    }
}
namespace ptsA
{
    int a[100009];
    ll ans=0;
    void mian()
    {
        for(int i=1; i<=n; i++)
        {
            int x, y, z;
            cin>>x>>y>>z;
            a[i]=x;
        }
        sort(a+1, a+1+n);
        int cnt=0;
        for(int i=n; cnt<=n/2; i--)
        {
            cnt++;
            ans+=a[i];
        }
        cout << ans << endl;
        return ;
    }
}
/*
namespace pts200
{
    int a[209][4];
    ll ans;
    ll f[2][105][105][105];
    ll maxll(ll x1, ll x3, ll x4)
    {
        return max(x1, max(x3, x4));
    }
    void mian()
    {
        for(int i=1; i<=n; i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }

        for(int i=1; i<=3; i++)
        {
            f[0][1][0][0]=a[1][1];
            f[0][0][1][0]=a[1][2];
            f[0][0][0][1]=a[1][3];
        }
        for(int i=0; i<=1; i++)
        {
            for(int j=1; j<=n/2; j++)
            {
                for(int k=1; k<=n/2; k++)
                {
                    int l=i-j-k;
                    f[i][j][k][l]=-inf;
                }
            }
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<=n/2; j++)
            {
                for(int k=0; k<=n/2; k++)
                {

                    int f1=0, f2=0, f3=0;
                    if(j>0)
                        f1=f[!(i%2)][j-1][k][l]+a[i][1];
                    else
                        f1=-inf;
                    if(k>0)
                        f2=f[!(i%2)][j][k-1][l]+a[i][2];
                    else
                        f2=-inf;
                    if(l>0)
                        f3=f[!(i%2)][j][k][l-1]+a[i][3];
                    else
                        f3=-inf;
                    f[i%2][j][k][l]=maxll(f1,f2,f3);
                    }
                }
            }


        ans=MINN;
        int maxi=MINN, maxj=MINN, maxl=MINN;
        for(int i=0; i<=n>>1; i++)
        {
            for(int j=0; j<=n>>1; j++)
            {
                int l=n-i-j;
                if(f[n%2][i][j][l]>ans && i+j+l==n)
                {
                    ans=f[n%2][i][j][l];
                    maxi=i;
                    maxj=j;
                    maxl=l;
                }

               // cout <<endl;
              //  ans=max(ans, f[n][i][j][n-i-j]);

            }
        }
        cout << ans << endl;
        return ;
    }
}
*/
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==2)
            pts2::mian();
        else if(n==4)
            pts4::mian();
        else if(n<=40)
            pts30::mian();
        else if(n<100000)
            pts200::mian();
        else
            ptsA::mian();

    }
    return 0;
}
