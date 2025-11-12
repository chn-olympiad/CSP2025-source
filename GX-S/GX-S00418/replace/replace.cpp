#include <iostream>
#include <string>
using namespace std;
int n,q;
string s[2][200005],t,u,v,w;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>s[0][i]>>s[1][i];
    for(int i=1;i<=q;++i)
    {
        cin>>t>>u;
        v=t,w=u;
        int cnt=0;
        for(int j=1;j<=n;++j)
        {
            t=v,u=w;
            if(t.find(s[0][j])!=-1)
            {
                int gt=t.find(s[0][j]);
                t=t.substr(0,gt)+s[1][j]+t.substr(gt+s[0][j].size());
                if(t==u)++cnt;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
