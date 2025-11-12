#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
    }
    string x,y;
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        ans=0;
        cin>>x>>y;
        for(int j=0;j<x.size();j++)
        {
            bool bbb=0;
            for(int k=0;k<j;k++)if(x[k]!=y[k])bbb=1;
            if(bbb)break;
            for(int k=1;k<=n;k++)
            {
                if(j+s[k][0].size()>x.size())continue;
                bool flag=0;
                for(int h=j;h<=j+s[k][0].size();h++)if(x[h]!=s[i][0][h]||y[h]!=s[i][1][h])
                {
                    flag=1;
                    break;
                }
                for(int h=j+s[k][0].size()+1;h<x.size();h++)if(x[h]!=y[h])
                {
                    flag=1;
                    break;
                }
                if(!flag)
                {
                    ans++;
                    cout<<j<<" "<<k<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
