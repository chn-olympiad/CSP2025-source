#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    vector<int> adj(10);
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' and s[i]<='9') adj[s[i]-'0']++;
    }

    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=adj[i];j++) cout<<i;
    }
    cout<<endl;
    return 0;
}
