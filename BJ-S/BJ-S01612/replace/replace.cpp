#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string a[200010];
string b[200010];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(q==1)
    {
        int ans=0;
        string x,y;
        cin>>x>>y;
        string tmp=x;
        for(int i=1;i<=n;i++)
        {
            int p=x.find(a[i]);
            if(p==-1)
            {
                continue;
            }
            for(int j=p;j<p+a[i].size();j++)
            {
                x[j]=b[i][j-p];
            }
            if(x==y)
            {
                ans++;
            }
            x=tmp;
        }
        cout<<ans;
    }
}
