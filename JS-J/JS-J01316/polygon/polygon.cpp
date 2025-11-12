#include<bits/stdc++.h>
using namespace std;
#define pq priority_queue<int,vector<int>,greater<int> >
#define ull unsigned long long
#define endl "\n"
const int N = 5005;
const int mod = 998244353;
int a[N];
map<int,int> cnt;
int main()
{
    //cout << mod;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    int ans = 0;
    for(ull i = 1;i <= (1<<n);i ++)
    {
        int maxn =-1,sum = 0;
        //cout << "rr " <<i << endl;
        for(ull j = 0;(1 << j) <= i;j ++)
        {
            //cout << (1<<j) << endl;
            if(i&(1<<j))
            {
                maxn = max(maxn,a[j+1]);
                sum += a[j+1];
            }
        }
        if(sum > maxn*2)
        {
            ans += 1;
            ans %= mod;
        }
    }
    cout << ans << endl;
}
