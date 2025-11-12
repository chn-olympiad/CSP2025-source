#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int t;
int a[100010][5];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        int maxn=-2147483647;
        int ans=0,flag;
        int sum1=0,sum2=0,sum3=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(maxn<a[i][j])
                {
                    maxn=a[i][j];
                    flag=j;
                }
            }
            if(flag==1)
            {
                 sum1+=maxn;
            }
            else if(flag==2)
            {
                 sum2+=maxn;
            }
            else if(flag==3)
            {
                 sum3+=maxn;
            }
        }
        ans+=(sum1+sum2+sum3);
        cout<<ans<<'\n';
        ans=0,sum1=0,sum2=0,sum3=0;
    }
    return 0;
}
