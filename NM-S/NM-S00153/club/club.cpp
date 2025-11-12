#include<bits/stdc++.h>
using namespace std;
int t,a[3][100001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,b[3];
        memset(a,0,sizeof(a));
        cin>>n;
        b[0]=n/2;
        b[1]=n/2;
        b[2]=n/2;
        for (int i=1;i<=n;i++)
        {
            cin>>a[0][i]>>a[1][i]>>a[2][i];
        }
        for (int j=1;j<=n;j++)
        {
            for (int i=0;i<3;i++)
            {
                if(b[i]>0)
                {
                    a[i][j]=max(a[0][j-1]+a[i][j],max(a[1][j-1]+a[i][j],a[2][j-1]+a[i][j]));
                }
                else
                {
                    if(i==0)
                    {
                        a[i][j]=max(a[1][j-1]+a[i][j],a[2][j-1]+a[i][j]);
                    }
                    if(i==1)
                    {
                        a[i][j]=max(a[0][j-1]+a[i][j],a[2][j-1]+a[i][j]);
                    }
                    if(i==2)
                    {
                        a[i][j]=max(a[1][j-1]+a[i][j],a[0][j-1]+a[i][j]);
                    }
                }
            }
            if(max(a[0][j],max(a[1][j],a[2][j]))==a[0][j])
            {
                b[0]--;
            }
            if(max(a[0][j],max(a[1][j],a[2][j]))==a[1][j])
            {
                b[1]--;
            }
            if(max(a[0][j],max(a[1][j],a[2][j]))==a[2][j])
            {
                b[2]--;
            }
        }
        cout<<max(a[0][n],max(a[1][n],a[2][n]));
    }
    return 0;
}
