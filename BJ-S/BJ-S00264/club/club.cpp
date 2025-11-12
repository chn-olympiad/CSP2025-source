#include<bits/stdc++.h>
using namespace std;






#define int long long
int dp[205][205][205];
struct stu{
int x, y, z;
}a[200005];
bool cmp(stu s1,stu s2)
{

    return s1.x>s2.x;
}
bool cmp1(stu s1,stu s2)
{



    int g=abs(s1.x-s1.y);
    int g1=abs(s2.x-s2.y);
    if(g>g1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
signed main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int _=1;_<=t;_++)
    {
        bool fa=1;
        bool fb=1;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {

            cin>>
            a[i].x
            >>a[i].y>>a[i].z;
            if(a[i].y==0&&a[i].z==0)
            {
                continue;
            }
            else if(a[i].y!=0&&a[i].z==0)
            {
                fa=0;
            }
            else
            {
                fa=0;
                fb=0;
            }

        }
        if(fa==1)
        {
            int ansp=0;
            sort(a+1,a+n+1,cmp);
            for(int j=1;j<=n/2;j++)
            {
                ansp+=a[j].x;
            }
            cout<<ansp;
            return 0;
        }
        else if(fb==1)
        {
            int ansp2=0;
            sort(a+1,a+n+1,cmp1);

            int l1=0;int l2=0;
            for(int p=1;p<=n;p++)
            {
                if(l1<n/2&&l1<n/2)
                {






                    if(a[p].x>=a[p].y)
                    {


                    ansp2+=a[p].x;
                    l1++;
                    }
                    else
                    {
                        ansp2+=
                        a[p].y;
                    }
                }
                else if(l1<n/2)
                {

                        ansp2+=a[p].x;


                }
                else
                {

                    ansp2+=a[p].y;
                }
            }
            cout<<ansp2;
            return 0;
        }
        else
        {
        memset(dp,-2e18,sizeof(dp));
        dp[0][0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                for(int k=0;k<=i;k++)
                {

                    int l=i-k-j;
                    if(k+j>n||k>n/2||j>n/2||l<0||l>n/2)
                    {
                        break;
                    }
                    else
                    {

                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].z);
                    }

                }

            }

        }

        int maxx=-1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i+j<=n)
                {
                    maxx=max(maxx,dp[n][i][j]);
                }
            }
        }
        cout<<maxx<<-1<<endl;
        }
    }


    return 0;
}
