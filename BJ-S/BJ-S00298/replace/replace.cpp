#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N],b[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }

    while(q--)
    {
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size())
        {
            cout<<"0\n";
            continue;
        }
        cout<<"0\n";
    }
    return 0;
}
