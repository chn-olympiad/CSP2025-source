#include<bits/stdc++.h>
using namespace std;
#define lc (p << 1)
#define rc (p << 1 | 1)
#define mid ((l + r) >> 1)
int a[500005];
long long b[500005];
int sum[500005 << 2];
void up(int p) {
    sum[p] = sum[lc] ^ sum[rc];
}
void build(int l, int r, int p){
    if(l == r){
        sum[p] = a[l];
        return ;
    }
    build(l, mid, lc);
    build(mid + 1, r, rc);
    up(p);
}

long long query(int ql, int qr, int l, int r, int p) {
    if (l == r || (ql <= l && r <= qr)){
        return sum[p];
    }
    long long ans = 0;
    if(ql <= mid) {
        ans = (long long) ans ^ query(ql, qr, l, mid, lc);
    }
    if (qr > mid) {
        ans = (long long) ans ^ query(ql, qr, mid + 1, r, rc);
    }
    return ans;
}
int main(){
    freopen("xor.in","r", stdin);
    freopen("xor.out","w", stdout);
    int n;
    long long k;
    cin >> n >> k;

    cin >> a[1];
    b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        b[i] = (long long)a[i] ^ b[i - 1];
    }
    if(n <=5000)
    build(1, n, 1);
    int i1, j1;
    int cnt = 0;
    for (int i = 1; i <= n;) {
        bool if1 = true;
        // int ac = (int)b[i] ^ b[i - 1];
        // if(ac == k ){
        //     i1 = i;
        //     j1 = i;
        //     if1 = false;
        //     cnt++;

        //     cout << i1 << ' ' << j1 << ' ' << ac << endl;
        //     i = j1 + 1;
        //     continue;
        // }
        for (int j = i ; j <= n; j++){
            if(n > 5000){
                long long ac = (long long) b[j] ^ b[i - 1];
                if(ac == k) {
                    i1 = i;
                    j1 = j;
                    if1 = false;
                    cnt++;
                    //cout << i1 << ' ' << j1 << endl;
                    break;
                }
            }

            else{
                if(query(i, j, 1, n, 1) == k){
                    i1 = i;
                    j1 = j;
                    if1 = false;
                    cnt++;
                    //cout << i1 << ' ' << j1 << endl;
                    break;
                }
            }

        }

        if(if1){
            i++;
        }else{
            i = j1 + 1;
        }
    }

    cout << cnt;
	return 0;
}
