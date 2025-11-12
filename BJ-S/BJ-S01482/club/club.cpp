#include<bits/stdc++.h>
using namespace std;
int maxx[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            maxx[i]=max(a1,max(a2,a3));
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans+=maxx[i];
        cout<<ans<<endl;
    }
    return 0;
}