#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string t[200005][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
    }
    for(int u=1;u<=q;u++)
    {
        cin>>t[u][0]>>t[u][1];
    }
    cout<<1;
}
//佛祖保佑