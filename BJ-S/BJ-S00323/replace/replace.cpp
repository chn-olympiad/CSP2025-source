#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,string> ma;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        ma[a]=b;
    }
    for(int i=1;i<=m;i++)
    {
        string a,b;
        cin>>a>>b;
        int ans=0;
        if(a.size()!=b.size()){cout<<0<<'\n';continue;}
        for(int i=0;i<=a.size();i++)
        {
            for(int j=a.size()-1;j>=i;j--)
            {
                if(a.substr(0,i)==b.substr(0,i)&&a.substr(j+1,a.size()-j)==b.substr(j+1,a.size()-j))
                {
                    if(ma.count(a.substr(i,j-i+1)))
                    {
                        if(ma[a.substr(i,j-i+1)]==b.substr(i,j-i+1))
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
