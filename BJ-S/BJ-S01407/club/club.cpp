#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[100005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=n/2;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>a[i]>>x>>y;
        }
        int ans=0;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=k;i++)
        {
            ans+=a[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
