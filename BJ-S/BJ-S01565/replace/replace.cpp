#include <bits/stdc++.h>

using namespace std;
struct node
{
    string a;
    string b;
}s[2000005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i = 1;i <= n;i ++)
    {
        cin>>s[i].a>>s[i].b;
        while(s[i].a[0] == s[i].b[0])
        {
            s[i].a.erase(0,1);
            s[i].b.erase(0,1);
        }
        while(s[i].a[s[i].a.length()-1] == s[i].b[s[i].b.length()-1])
        {
            s[i].a.erase(s[i].a.length()-1,1);
            s[i].b.erase(s[i].b.length()-1,1);
        }
    }
    for(int i = 1;i <= q;i ++)
    {
        string x,y;
        cin>>x>>y;
        if(x == y) cout<<0<<endl;
        while(x[0] == y[0])
        {
            x.erase(0,1);
            y.erase(0,1);
        }
        while(x[x.length()-1] == y[y.length()-1])
        {
            x.erase(x.length()-1,1);
            y.erase(y.length()-1,1);
        }
        int ans = 0 ;
        for(int i = 1;i <= n;i ++)
        {
            if(x == s[i].a && y == s[i].b) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
