#include<bist/stdc++.h>
using namespace std;
int maxs(int i)
{
    if(a[i][1]>=a[i][2]) int max=a[i][1];
    else max=a[i][2];
    if(max>a[i][3]) max+=0;
    else max=a[i][3];
    return max;
}
{
    freopen("club.in";"r";stdin);
    freopen("club.out";"w";stdout);
    int t;
    cin>>t;
    for(int w=1;w<=t;w++)
    {
        int n,ans;
        cin>>n;
        int a[n+1][3];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1];
            cin>>a[i][2];
            cin>>a[i][3];
        }
        if(for(int i=1;i<=n;i++)
        {
            a[i][1]==0&&a[i][3]==0
        })
        {
            int m[n+1];
            for(int i=1;i<=n;i++)
            {
                m[i]=a[i][2];
            }
            sort(m[1],m[1+n-1])
            for(int i=n;i>n/2;i--)
            {
                ans+=m[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans+=maxs(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
