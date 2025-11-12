#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;cin>>n>>k;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum=0;map<int,int> mp;
    vector<pair<int,int>> s(n+5);int cnt=0;//[r,l]
    mp[0]=1;
    for(int i=1;i<=n;i++)
    {
        sum^=a[i];
        int m=k^sum;
        if(a[i]==k) s[++cnt]={i,i};
        else if(mp[m]) s[++cnt]={i,mp[m]};
        mp[sum]=i+1;
    }

    sort(s.begin()+1,s.begin()+1+cnt);
    int R=0,ans=0;
    auto check=[&](int l)->bool
    {
        if(l<=R) return 0;
        else return 1;
    };
    for(int i=1;i<=cnt;i++)
    {
        int r=s[i].first,l=s[i].second;
        if(check(l))
        {
            R=r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}