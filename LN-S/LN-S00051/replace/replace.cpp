#include <bits/stdc++.h>
using namespace std;
int n,q,ans,cnt,l,lx,xbx,xby,xbz;
bool flag;
string x[200005];
string y[200005];
string z[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        cin>>y[i]>>z[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<n;i++)
    {
        cnt=0;
        flag=false;
        l=y[i].size();
        lx=x[i].size();
        for(int j=0;j<l;j++)
        {
            if(y[i][j]=='b')
            {
                xby=j;
                break;
            }
            if(z[i][j]=='b')
            {
                xbz=j;
                break;
            }
            if(x[i][j]=='b')
            {
                xbx=j;
                break;
            }
        }
        if(xbx>=xby&&xbx>=xbz&&(lx-xbx)>=(l-xby)&&(lx-xbx)>=(l-xby))
        {
            ans=1;
        }
    }
    cout<<ans;
    return 0;
}
