#include <bits/stdc++.h>
using namespace std;
int t,n,tmpa[100001],tmpb[100001],tmpc[100001];
long long ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;ans=0;
        for(int j = 0;j<n;++j)
        {
            cin>>tmpa[j]>>tmpb[j]>>tmpc[j];
        }
        sort(tmpa,tmpa+n);
        for(int j=n-1;j>=n/2;j--)
        {
            ans+=tmpa[j];
        }
        cout << ans << endl;
    }
    return 0;
}
