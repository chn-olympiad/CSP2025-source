#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10,nops=18446744073709551615;
int n,q;
string a[N],b[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    while(q--)
    {
        string u,v;
        int ans=0;
        cin>>u>>v;
        for(int i=1;i<=n;i++)
        {
            string p,q;
            int r=u.find(a[i]);
            if(r==nops) continue;
            p=u.substr(0,r);
            int f=r+a[i].size(),g=u.size();
            q=u.substr(f,g);
            if(p+b[i]+q==v) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
