#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long a[N][5],ans;
struct P
{
    long long v;
    int cnt[5];
}f[305][305][5];
void work(int x,int i,int j,int k,long long v)
{
    if(x>n)
    {
        ans=max(ans,v);
        return;
    }
    if(i<(n/2))
    {
        work(x+1,i+1,j,k,v+a[x][1]);
    }
    if(j<(n/2))
    {
        work(x+1,i,j+1,k,v+a[x][2]);
    }
    if(k<(n/2))
    {
        work(x+1,i,j,k+1,v+a[x][3]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof f);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        if(n<=10)
        {
            work(1,0,0,0,0);
            cout<<ans<<endl;
            ans=0;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n/2;j++)
            {
                long long ans=0;
                for(int k=1;k<=3;k++)
                {
                    for(int l=1;l<=3;l++)
                    {
                        if(f[i-1][(l==k?j:(n/2))][l].cnt[k]<=j)
                        {
                            if(f[i][j][k].v<f[i-1][(l==k?j:(n/2))][l].v)
                            {
                                f[i][j][k].v=f[i-1][(l==k?j:(n/2))][l].v;
                                f[i][j][k].cnt[2]=f[i-1][(l==k?j:(n/2))][l].cnt[2];
                                f[i][j][k].cnt[3]=f[i-1][(l==k?j:(n/2))][l].cnt[3];
                                f[i][j][k].cnt[1]=f[i-1][(l==k?j:(n/2))][l].cnt[1];
                            }
                        }
                    }
                    for(int l=1;l<=3;l++)
                    {
                        if(f[i-1][(l==k?j-1:(n/2))][l].cnt[k]<=j-1)
                        {
                            if(f[i][j][k].v<f[i-1][(l==k?j-1:(n/2))][l].v+a[i][k])
                            {
                                f[i][j][k].v=f[i-1][(l==k?j-1:(n/2))][l].v+a[i][k];
                                f[i][j][k].cnt[2]=f[i-1][(l==k?j-1:(n/2))][l].cnt[2];
                                f[i][j][k].cnt[3]=f[i-1][(l==k?j-1:(n/2))][l].cnt[3];
                                f[i][j][k].cnt[1]=f[i-1][(l==k?j-1:(n/2))][l].cnt[1];
                                f[i][j][k].cnt[k]++;
                            }
                        }
                    }
                }
            }
        }
        long long res=0;
        for(int k=1;k<=3;k++)
        {
            res=max(res,f[n][n/2][k].v);
        }
        cout<<res<<endl;
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
