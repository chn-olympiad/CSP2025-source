#include <bits/stdc++.h>
using namespace std;

struct node{
    int a, b, c;
};

bool cmp(node a, node b) {
    return a.a > b.a;
}

bool cmp1(node a, node b) {
    return max(a.a, a.b) > max(b.a, b.b);
}

int main(){
    ios::sync_with_stdio(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int cnt = 0;
        int n, lena = 0, lenb = 0;
        bool ci = 0, bi = 0;
        vector<node> a(n+1, {0, 0, 0});
        cin >> n;
        int k = n/2;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if(ci != 0) break;
            if(bi != 0) bi = 1;
        }
        if(ci == 0) {
            if(bi == 0) {
                sort(a.begin()+1, a.end(), cmp);
                for(int i = 1; i <= k; i++) {
                    cnt += a[i].a;
                }
                cout << cnt << endl;
                continue;
            }
            sort(a.begin()+1, a.end(), cmp1);
            for(int i = 1; i <= n; i++) {
                if(a[i].a > a[i].b) {
                    cnt += a[i].a;
                    lena++;
                } else {
                    cnt += a[i].b;
                    lenb++;
                }
                if(lena == k) {
                    for(int j  = i + 1; j <= n; j++) {
                        cnt += a[j].b;
                    }
                    cout << cnt << endl;
                    break;
                }
                if(lenb == k) {
                    for(int j  = i + 1; j <= n; j++) {
                        cnt += a[j].a;
                    }
                    cout << cnt << endl;
                    break;
                }
            }
        }
        // for(int i = 1; i <= n; i++) {
        //     if(max({a[i].a, a[i].b, a[i].c}) == a[i].a) {
        //         x.push_back(a[i].a);
        //         cnt += a[i].a;
        //     } else if(max({a[i].a, a[i].b, a[i].c}) == a[i].b) {
        //         y.push_back(a[i].b);
        //         cnt += a[i].b;
        //     } else {
        //         z.push_back(a[i].c);
        //         cnt += a[i].c;
        //     }
        // }

    }
}