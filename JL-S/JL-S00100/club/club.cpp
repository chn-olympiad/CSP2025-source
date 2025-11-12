#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,sum=0;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        sum=0;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=3;k++)
            {
                cin>>a[j][k];
            }
            int c=0;
            for(int k=1;k<=3;k++)
            {
                if(a[j][k]>a[j][k+1] && k!=3)
                {
                    c=a[j][k];
                }
            }
            sum+=c;
        }
        cout<<sum;
    }
    return 0;
}
