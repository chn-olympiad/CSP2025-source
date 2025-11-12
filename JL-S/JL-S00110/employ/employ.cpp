#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0;
string s;
int c[505];
int f(int n)
{
    if(n==1) return n;
    return n*f(n-1);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    ans+=f(n);
    cout<<ans;
    return 0;
}
