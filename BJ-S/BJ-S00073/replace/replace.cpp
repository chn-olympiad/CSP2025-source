#include <bits/stdc++.h>
using namespace std;
const int N=200005;
string a[N],b[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    while(q--)
    {
        string u,v;
        cin>>u>>v;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<u.size()-a[i].size()+1;j++)
            {
                bool flag=0;
                for(int k=0;k<a[i].size();k++)
                {
                    if(a[i][k]!=u[j+k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    string x=u;
                    for(int k=0;k<a[i].size();k++)
                    {
                        x[j+k]=b[i][k];
                    }
                    if(x==v)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
