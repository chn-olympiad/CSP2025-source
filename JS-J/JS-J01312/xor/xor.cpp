#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
struct node{int l,r;}tk[N];
int a[N],n,k,mx = 0,mn = 1e9;
int s[N],cnt = 0;
int v[N],ans = 0;
bool cmp(node x,node y){
    if(x.r == y.r) return x.l > y.l;
    return x.r < y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;s[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        s[i] = s[i-1]^a[i];
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    if(k == 0 && mx == 1 && mn == 1){
        cout << n/2;
        return 0;
    }
    if(mx < 2 && k == 1){
        int l = 0,r = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] == 0) l++;
            else r++;
        }
        cout << r;
        return 0;
    }
    for(int len = 1;len <= n;len++){
        for(int i = 1;i <= n-len+1;i++){
  //          cout << i << " " << j << " " << (s[j]^s[i-1]) << "\n";
            int j = i+len-1;
            if((s[j]^s[i-1]) == k) tk[++cnt] = {i,j};
        }
    }
    sort(tk+1,tk+cnt+1,cmp);
    for(int i = 1;i <= cnt;i++){
        int f = 0;
        for(int j = tk[i].l;j <= tk[i].r;j++){
            if(v[j] == 1){
                f = 1;
                break;
            }
        }
        if(f) continue;
        for(int j = tk[i].l;j <= tk[i].r;j++) v[j] = 1;
        ans++;
    }
    cout << ans;
    return 0;
}
