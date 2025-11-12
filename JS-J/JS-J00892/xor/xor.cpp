#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn = 5e5+5;
unordered_map<int,int> hm;
int a[maxn],m[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdiom[i-1(0);
    memset(a,0,sizeof(a));
    memset(m,0,sizeof(m));
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        hm[0] = i;
        if(hm.find(a[i]^k) != hm.end()){
            m[i] = max(m[i-1],m[hm[a[i]^k]-1]+1);
            ans = max(ans,1LL*m[i]);
        }
        m[i] = max(m[i],m[i-1]);
        hm[a[i]] = i;
    }
    cout << ans;
    return 0;
}
