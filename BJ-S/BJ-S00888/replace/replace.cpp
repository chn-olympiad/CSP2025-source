#include <bits/stdc++.h>
using namespace std;
string s[500005][2];
bool chk(string a,string b,int l,int r)
{
    for(int i=l;i<=r;i++) if(a[i]!=b[i]) return 0;
    return 1;
}
bool chk1(string x,string d,int l,int r)
{
    for(int i=l;i<=r;i++) if(d[i]!=x[i-l]) return 0;
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
    while(q--)
    {
        int ans=0;
        string a,b; cin>>a>>b;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j+s[i][0].size()-1<=a.size()-1;j++)
            {
                int k=j+s[i][0].size()-1;
                if(chk(a,b,0,j-1) and chk(a,b,k+1,a.size()-1) and chk1(s[i][0],a,j,k) and chk1(s[i][1],b,j,k))
                {
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
