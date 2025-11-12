#include <bits/stdc++.h>
using namespace std;
int a[500000];
map<int,vector<int> > b;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        a[i]^=a[i-1];
        b[a[i]^k].push_back(i);
    }
    vector<pair<int,int> > v;
    for(int i=1,minn;i<=n;i++)
    {
        minn=n+1;
        for(int j=0;j<b[a[i]].size();j++)
        {
            if(b[i][j>i])
                minn=min(minn,b[i][j]);
        }
        v.push_back({minn,a[i]});
    }
    sort(v.begin(),v.end());
    for(int i=0,now=0;i<v.size();i++)
    {
        if(v[i].second<now)
            continue;
        ++ans;
        now=v[i].second;
    }
    cout<<ans<<endl;
//    cout<<"VICTOR"<<endl;
    return 0;
}
