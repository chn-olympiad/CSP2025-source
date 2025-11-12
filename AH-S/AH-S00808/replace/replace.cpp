#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string s1[N],s2[N],t1[N],t2[N];
int n,q,ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int aa,bb;
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1[i]>>t2[i];
    }
    for(int i=1;i<=q;i++)
    {
        ans=0;
        if(t1[i].size()!=t2[i].size())
        {
            cout<<"0\n";
            continue;
        }
        for(int j=1;j<=n;j++)
        {
            int u=t1[i].find(s1[j]),v=t2[i].find(s2[j]);
            if(u==v&&u!=string::npos&&v!=string::npos)
                ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
