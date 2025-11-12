#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a;
    for(int i = 1;i <= n;i ++)
    {
        cin>>a;
    }
    int ans1 = 1,ans2 = 1;
    int ans = 0;
    for(int i = 1;i <= m-1;i ++)
    {
        ans1*=i;
        ans2*=n-i+1;
    }
    for(int i = m;i <= n;i ++)
    {
        ans1*=i;
        ans2*=n-i+1;
        ans+=ans2/ans1;
    }
    cout<<ans<<endl;
    return 0;
}
