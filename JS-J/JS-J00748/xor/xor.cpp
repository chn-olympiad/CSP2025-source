#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
const int maxa = (1 << 20) + 5;
int n,k;
int a[maxn],sum[maxn];
int nxt[maxn];
struct node{
    int l,r;
};
vector<node> v;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    memset(nxt,-1, sizeof nxt);
    nxt[sum[n]] = n;
    v.clear();
    // for(int i = 1;i <= n;i++) cout << sum[i] << " \n"[i == n];
    for(int i = n - 1;i >= 0;i--)
    {
        // cout << i << ' ' << (sum[i]^k) << ' ' << nxt[sum[i] ^ k] << '\n';
        if(nxt[sum[i]^k] == -1) 
        {
            nxt[sum[i]] = i;
            continue;
        }
        int len = (int)v.size();
        if(len == 0 || v[len - 1].r > nxt[sum[i]^k]) v.push_back({i + 1,nxt[sum[i]^k]});
        nxt[sum[i]] = i;
    }
    // for(int i = 0;i < v.size();i++)
    // {
    //     cout << v[i].l << ' ' << v[i].r << endl;
    // }
    reverse(v.begin(),v.end());
    if((int)v.size() == 0) 
    {
        cout << "0\n";
        return 0;
    }
    int R = v[0].r,ans = 1;
    for(int i = 1;i < v.size();i++)
    {
        if(R < v[i].l)
        {
            R = v[i].r;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}