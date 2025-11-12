#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>b[i]&&a[i]>c[i])
            {
                ans+=a[i];
            }
            if(b[i]>c[i]&&b[i]>a[i])
            {
                ans+=b[i];
            }
            if(c[i]>a[i]&&c[i]>b[i])
            {
              ans+=c[i];
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
