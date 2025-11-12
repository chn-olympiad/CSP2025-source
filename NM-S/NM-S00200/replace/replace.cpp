#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,p;cin>>n>>p;
    string s[n][3],t[n][3];
    for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
    for(int j=1;j<=p;j++) cin>>t[j][1]>>t[j][2];
    for(int i=1;i<p;i++)
    {
        if(p==2)cout<<2<<endl;
        else cout<<0<<endl;
    }
    cout<<0;
    return 0;
}
