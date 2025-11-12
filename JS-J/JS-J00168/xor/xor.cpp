#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
vector<int> g[N];
int f[500005];
struct stu{
    int l,r;
}a[1000000];
int cnt;
bool cmp(stu b,stu c){
    if(b.r != c.r) return b.r < c.r;
    return b.l< c.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    g[0].push_back(0);
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        f[i] = f[i - 1] ^ x;
      //  cout << f[i] << '\n';
        g[f[i]].push_back(i);
    }
    for(int i = 1;i <= n;i ++){
        int q = k ^ f[i - 1];
        for(int j = 0;j < g[q].size();j ++){
            if(g[q][j] >= i){
                cnt ++;
                a[cnt] = {i,g[q][j]};
            }
        }
    }
   // cout << cnt << '\n';
   // for(int i = 1;i <= cnt;i ++) cout << a[i].l << " " << a[i].r << '\n';
    sort(a+1,a+cnt+1,cmp);
    int r = 0;
    int ans = 0;
    for(int i = 1;i <= cnt;i ++){
        if(a[i].l > r){
            ans ++;
            r = a[i].r;
            //cout << r << '\n';
        }
        //cout << a[i].l << " " << a[i].r << '\n';
    }
    cout << ans;
    return 0;
}