#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,string> c;
void work(string a,string b)
{
    if(a.length()!=b.length())
    {
        cout<<"0\n";
        return;
    }
    int ans=0,n=a.length();
    a=' '+a,b=' '+b;
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            string t=a.substr(l,r-l+1);
            string tt=a;
            if(c[t]!="")
            {
                tt.replace(l,r-l+1,c[t]);
                if(tt==b)
                    ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
int n,m;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        c[a]=b;
    }
    for(int i=1;i<=m;i++)
    {
        string a,b;
        cin>>a>>b;
        work(a,b);
    }
    return 0;
}