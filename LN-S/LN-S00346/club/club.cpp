#include<iostream>
#include<cstdio>
using namespace std;
int t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            ans+=max(a,max(b,c));
        }
        cout<<ans<<endl;
    }
    return 0;
}
