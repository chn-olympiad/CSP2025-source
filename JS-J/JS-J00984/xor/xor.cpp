#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;
const int M = 5e5 + 5;
int a[M], sum[N][N], op[M], vis[M];

struct node{
    int a, b;
}qp[N * N];

bool cmp(node a, node b){
    return a.b < b.b;
}

int main() {

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;

    cin >> n >> k;

    int cnt0 = 0, cnt1 = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1) cnt1++;
        if(a[i] == 0) cnt0++;
        if(i == 1) op[i] = a[i];
        else op[i] = op[i - 1] ^ a[i];
    }

    if(k == 1 && cnt1 + cnt0 == n){
        cout << cnt1 << endl;
    }
    else if(k == 0 && cnt1 + cnt0 == n){
        int ans = cnt0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 1 && a[i - 1] == 1){
                ans++;
                a[i] = a[i - 1] = 0;
            }
        }
        cout << ans << endl;
    }
    else {
        int cnt = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                sum[i][j] = op[j] ^ op[i - 1];
                if(i == 1){
                    sum[i][j] = op[j];
                }
                if(i == j){
                    sum[i][j] = a[i];
                }
                if(sum[i][j] == k){
                    qp[++cnt].a = i, qp[cnt].b = j;
                }
            }
        }
        sort(qp + 1, qp + 1 + cnt, cmp);
        for(int i = 1; i <= cnt; i++){
            int l = qp[i].a, r = qp[i].b;
            int f = 0;
            while(l <= r){
                if(vis[l]) {
                    f = 1;
                    break;
                }
                l++;
            }
            if(!f){
                l = qp[i].a;
                while(l <= r){
                    vis[l] = true;
                    l++;
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}