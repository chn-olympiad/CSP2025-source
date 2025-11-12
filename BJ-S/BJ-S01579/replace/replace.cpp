#include <bits/stdc++.h>

using namespace std;
string a[200005],b[200005];
bool check(string t,string u,int p)
{
    for(int i=0;i<u.length();i++)
        if(t[i+p]!=u[i])return 0;
    return 1;
}
string rep(string t,string u,int p)
{
    for(int i=0;i<u.length();i++)
        t[i+p]=u[i];
    return t;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=0;i<q;i++)
    {
        string c,d;
        int ans=0;
        cin>>c>>d;
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<=int(c.length())-int(a[j].length());k++)
            {
                if(check(c,a[j],k)&&rep(c,b[j],k)==d)
                {
                    ans++;
                }
            }
            //cout<<j<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}