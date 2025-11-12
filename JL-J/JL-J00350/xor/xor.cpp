#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n,k,ans;
int sum[maxn],a[maxn],f[maxn];
int t[maxn * 40];
int mx = 5e6 + 10;
int query(int k,int l,int r,int idx){
    int ls = k << 1;
    int rs = (k << 1) | 1;
    if(l == r){
        return t[k];
    }
    int mid = (l + r) >> 1;
    if(idx <= mid) return query(ls,l,mid,idx);
    else return query(rs,mid + 1,r,idx);

}
void update(int k,int l,int r,int idx,int x){
    int ls = k << 1;
    int rs = (k << 1) | 1;
    if(l == r){
        t[k] = x;
        return;
    }
    int mid = (l + r ) >> 1;
    if(idx <= mid) update(ls,l,mid,idx,x);
    else update(rs,mid + 1,r,idx,x);
    t[k] = t[ls] + t[rs];
}
void work1(){
    if(k == 0){
        int ans = 0;
        for(int i = 1 ; i <= n ; i ++){
            if(!a[i]) ++ ans;
        }
        int idx  = 1;
        while(idx <= n){
            int idx2 = idx;
            //cout << idx << ' ' << idx2 << endl;
            while(a[idx2 + 1] && idx2 + 1 <= n) ++ idx2;
            ans += ((idx2 - idx + 1) / 2);
            while(!a[idx + 1] && idx + 1 <= n) ++ idx;
            ++ idx;
        }
        cout << ans; 
    }
    else{
        int ans = 0;
        for(int i = 1 ; i <= n ; i ++) ans += a[i];
        cout << ans;
    }
    return;
}
void work2(){
    for(int i = 1 ; i <= n ; i ++) {
        sum[i] = sum[i - 1] ^ a[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        f[i] = f[i - 1];
        int flag = 0;
        for(int j = i ; j >= 1 ; j --){
            if((sum[i] ^ sum[j - 1]) == k) flag = 1;
        }
        if(! flag) f[i] = f[i - 1];
        else{
            for(int j = i ; j >= 1 ; j --) {
                if((sum[i] ^ sum[j - 1]) == k) f[i] = max(f[i],f[j - 1] + 1);
            }
        }
    }
    cout << f[n];
}
void work3(){
    int y = 0;
    for(int i = 1 ; i <= n ; i ++) {
        sum[i] = sum[i - 1] ^ a[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        f[i] = f[i - 1];
        f[i] = max(f[i],query(1,1,mx,(sum[i] ^ k)) + 1);
        update(1,1,mx,sum[i],f[i]);
        y = max(y,f[i]);
    }
    cout << y;

}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    int flag1 = 1,flag2 = 1;//flag1 A flag2 B
    for(int i = 1 ; i <= n ; i ++) {
        cin >> a[i];
        if(a[i] != 1 ) flag1 = 0;
        if(a[i] > 1) flag2 = 0;
    }
    if(n <= 1000) work2();
    else if(flag1) cout << (n / 2);
    else if(flag2) work1();
    else work3();
    return 0;
}