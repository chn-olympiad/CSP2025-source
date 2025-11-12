#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
const int _mxn=2e5+5;
int n;
pair<string,string> s[_mxn];
int main()
{
    ___();
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i].first>>s[i].second;
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        if(t1.length()!=t2.length())
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=t1.length()-s[i].first.length();j++)
            {
                if(t1.substr(0,j)!=t2.substr(0,j))
                    break;
                if(t1.substr(j,s[i].first.length())==s[i].first&&t2.substr(j,s[i].second.length())==s[i].second&&t1.substr(j+s[i].first.length())==t2.substr(j+s[i].second.length()))
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}