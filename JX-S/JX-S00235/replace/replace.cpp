#include <bits/stdc++.h>
using namespace std;
string a[200037],b[200037],x,y;
int d[200037][3],n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i].length();j++)
        {
            if(a[i][j]=='1')d[i][1]=j;
            if(b[i][j]=='1')d[i][2]=j;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(x.length()!=y.length())
        {
            cout<<0<<endl;
            continue;
        }
        int dx,dy;
        for(int j=0;j<x.length();j++)
        {
            if(x[j]=='1')dx=j;
            if(y[j]=='1')dy=j;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dy-dx!=d[i][2]-d[i][1])
            {
                continue;
            }
            if(min(d[i][1],d[i][2])>min(dx,dy))
            {
                continue;
            }
            if(a[i].length()-max(d[i][1],d[i][2])>x.length()-max(dx,dy))
            {
                continue;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
