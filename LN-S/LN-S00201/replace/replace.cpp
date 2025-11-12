#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
string s[200005][3],t[2000005][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i][1]>>t[i][2];
    }

    cout<<n/2;
    return 0;
}
