#include<bits/stdc++.h>
int t;
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int a[100000][4];
        int f[100000][4];
        int q[4];
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }

        for(int i=1;i<=n;i++)
        {
            int maxn=0;
            int pos=0;
            for(int j=1;j<=3;j++)
            {
                if(q[j]+1<=n/2&&a[i-1][j]>=maxn)
                {
                    maxn=a[i-1][j];
                    pos=j;
                }
            }
            q[pos]++;
            for(int j=1;j<=3;j++)
            {
                f[i][j]=f[i-1][pos]+a[i][j];
            }


        }
        int maxn=0;
        for(int j=1;j<=3;j++)
        {
            maxn=max(f[n][j],maxn);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
