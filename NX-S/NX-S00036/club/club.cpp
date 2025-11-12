#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int v=1;v<=t;v++)
    {
        int n;
        long long ans=0;
        int a1[100010],a2[100010],a3[100010];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        sort(a1+1,a1+n+1);
        int m=0;
        for(int i=n;i>=1;i--)
        {
            if(m<n/2)
            {
                ans+=a1[i];
                m++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
