#include <bits/stdc++.h>
#define lc (p<<1)
#define rc (p<<1|1)
using namespace std;
const int N = 5e5 + 10;
int n,k,ans,a[N],s[N];
struct node{
    int l,r,sum,lzy;
}t[N<<2];
void build(int p,int l,int r){
    t[p] = {l,r,0};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lc,l,mid);
    build(rc,mid + 1,r);
}
void pushdown(int p){
    if(t[p].lzy){
        t[lc].sum = t[p].lzy * (t[lc].r - t[lc].l + 1);
        t[rc].sum = t[p].lzy * (t[rc].r - t[rc].l + 1);
        t[lc].lzy = t[p].lzy;
        t[rc].lzy = t[p].lzy;
        t[p].lzy = 0;
    }
}
void update(int p,int x,int y,int k){
    if(x <= t[p].l && t[p].r <= y){
        t[p].sum = (t[p].r - t[p].l + 1) * k;
        t[p].lzy = k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if(x <= mid) update(lc,x,y,k);
    if(mid < y) update(rc,x,y,k);
    t[p].sum = t[lc].sum + t[rc].sum;
}
int query(int p,int x,int y){
    if(x <= t[p].l && t[p].r <= y) return t[p].sum;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1,cnt = 0;
    if(x <= mid) cnt += query(lc,x,y);
    if(mid < y) cnt += query(rc,x,y);
    return cnt;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]),s[i] = s[i-1] ^ a[i];
    if(k == 1){
        for(int i = 1;i <= n;i++)
            if(a[i] == 1) ans++;
        cout << ans;
        return 0;
    }else if(k == 0){
        for(int i = 1;i <= n;i++)
            if(a[i] == 0) ans++;
            else if(a[i] ==  a[i+1]) ans++,i++;
        cout << ans;
        return 0;
    }
    build(1,1,n);
    for(int i = 1;i <= n;i++){
        if(n - query(1,1,n) < i) break;
        for(int j = 1;j + i - 1 <= n;j++){
            int cnt = s[j+i-1] ^ s[j-1];
            if(cnt == k && !query(1,j,j + i - 1))
                update(1,j,j + i - 1,1),ans++;
        }
    }
    cout << ans;
    return 0;
}
