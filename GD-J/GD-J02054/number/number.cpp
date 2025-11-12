#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    string s;cin>>s;int n=s.size();
    vector<int> mp(20);
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9') mp[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        while(mp[i])
        {
            cout<<i;
            mp[i]--;
        }
    }
    cout<<"\n";
    return 0;
}