#include <bits/stdc++.h>
#define ll long long
const ll MOD=998244353;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m; cin>>n>>m;
    vector<char> a(n);
    vector<char> test;
    for (auto &i:a) cin>>i;
    for (auto i:a) test.push_back(i);
    sort(test.begin(),test.end());
    int cnt=0;
    vector<int> pl(n);
    for (auto &i:pl) cin>>i;
    for (auto i:a) cnt+=(i=='0');
    ll ans=1;
    if ((n-cnt)<m) {
        cout<<0;
        return 0;
    }
    if (test[0]=='1') {
        for (int i=1;i<=m;i++) {
            ans*=i;
            ans%=MOD;
        }
        cout<<ans;
        return 0;
    }
    auto canadd=[&](const vector<int> &x) {
        int note=0;
        int tem=0;
        for (int i=0;i<n;i++) {
            if (note>=pl[x[i]]) {note++; continue;}
            if (a[i]=='0') note++;
            else tem++;
        }
        return tem>=m;
    } ;
    ans = 0;
    vector<int> nums;
    for (int i=0;i<n;i++) nums.push_back(i);
    do {
        ans+=canadd(nums);
    } while (next_permutation(nums.begin(),nums.end()));
    cout<<ans%MOD;
    return 0;
}
