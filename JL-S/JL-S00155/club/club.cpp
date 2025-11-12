#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n;
    int a[100010];
    cin>>T;
    while(T--)
    {
        int x,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>x>>x;
        }
        sort (a+1,a+1+n);
        for(int i=n;i>=n/2+1;i--)
        {
            //cout<<a[i];
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
