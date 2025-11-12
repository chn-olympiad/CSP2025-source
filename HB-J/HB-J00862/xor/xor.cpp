#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long s[N];
struct node
{
    int l,r;
    bool operator<(const node &A)const
    {
        return r<A.r;
    }
};
vector<node>v;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        long long a;
        cin>>a;
        s[i]=(s[i-1]^a);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            if ((s[j]^s[i-1])==k)
            {
                v.push_back({i,j});
            }
        }
    }
    sort(v.begin(),v.end());
    int ans=0,r=0;
    for (int i=0;i<v.size();i++)
    {
        if (r<v[i].l)
        {
            ans++;
            r=v[i].r;
        }
    }
    cout<<ans;
    return 0;
}
