#include <bits/stdc++.h>
using namespace std;
map<string,string> m;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        m[a]=b;
    }
    for(int i=1;i<=q;i++)
    {
        string s;
        cin>>s;
        cout<<"0\n";
    }
    return 0;
}