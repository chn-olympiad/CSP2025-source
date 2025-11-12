#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005];
struct node
{
    int l;
    int r;
};
bool cmp(node a,node b)
{
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
vector<node>ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)a[i]^=a[i-1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)ans.push_back({1,i});
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((a[j]^a[i-1])==k)
            {
                ans.push_back({i,j});
            }
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    ll cur=0,cnt=0;
    for(auto v : ans)
    {
        if(v.l>cur)cnt++;
        cur=v.r;
    }
    cout<<cnt<<endl;
    return 0;
}
