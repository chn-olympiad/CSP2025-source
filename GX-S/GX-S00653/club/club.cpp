#include <bits/stdc++.h>
using namespace std;

int n, t, ans, num, sum, cnt, d, g;
int a[10], b[10], c[10], aa[1000010], bb[1000010], cc[1000010];
int aaaa[1000010], bbbb[1000010], cccc[1000010], xyz[1000010];
int f[3];

void aaa(int x, int z){
    if(max(x, z) == x && num < g){
        num++;
        ans += x;
    }
    else{
        cnt++;
        ans += z;
    }
}

void bbb(int y, int z){
    if(max(z, y) == y && sum < g){
        sum++;
        ans += z;
    }
    else{
        cnt++;
        ans += z;
    }
}

void ccc(int y, int x){
    if(max(x, y) == y && sum < g){
        sum++;
        ans += y;
    }
    else{
        num++;
        ans += x;
    }
}

int main(){

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while(t--){
        ans = 0;
        num = 0;
        sum = 0;
        cnt = 0;
        cin >> n;
        g = n / 2;
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i] >> c[i];
 //           aa[i] = a[i];
 //           bb[i] = b[i];
 //           cc[i] = c[i];
        }
       /* sort(aa + 1, aa + n + 1);
        sort(bb + 1, bb + n + 1);
        sort(cc + 1, cc + n + 1);
        int m = 0;
        for(int i = 1; i <= n; i++){
            if(aa[i] == a[i]){
                aaaa[++m] = i;
            }
            if(bb[i] == b[i]){
                bbbb[++m] = i;
            }
            if(cc[i] == c[i]){
                cccc[++m] = i;
            }
        }
        int p;
        for(int i = 1; i <= n; i++){
            if(aaaa[i] != bbbb[i] && cccc[i] != bbbb[i] && aaaa[i] != cccc[i])
                for(int j = 1; j <= p; j++){
                    if(aaaa[j] == xyz[j])
                        f[1] == 1;
                    if(bbbb[j] == xyz[j])
                        f[2] == 2;
                    if(cccc[j] == xyz[j])
                        f[3] == 3;
                }
                if(sum < g && f[1] == 0){
                        ans += aa[i];
                        xyz[++p] = i;
                        sum++;
                }
                if(num < g && f[2] == 0){
                        ans += bb[i];
                        xyz[++p] = i;
                        num++;
                }
                if(cnt < g && f[3] == 0){
                        ans += cc[i];
                        cnt++;
                }
            if(aaaa[i] == bbbb[i] && cccc[i] != bbbb[i] && aaaa[i] != cccc[i]){
                if(aa[aaaa[i]] > bb[bbbb[i]]){
                for(int j = 1; j <= p; j++){
                    if(aaaa[j] == xyz[j])
                        f[2] == 2;
                    if(cccc[j] == xyz[j])
                        f[3] == 3;
                }
                if(sum < g && f[1] == 0){
                        ans += aa[i];
                        xyz[++p] = i;
                        sum++;
                }
                if(cnt < g && f[3] == 0){
                        ans += cc[i];
                        xyz[++p] = i;
                        cnt++;
                }
                }
                else{
                    for(int j = 1; j <= p; j++){
                    if(bbbb[j] == xyz[j])
                        f[2] == 2;
                    if(cccc[j] == xyz[j])
                        f[3] == 3;
                }
                if(num < g && f[2] == 0){
                        ans += bb[i];
                        xyz[++p] = i;
                        num++;
                }
                if(cnt < g && f[3] == 0){
                        xyz[++p] = i;
                        ans += cc[i];
                        cnt++;
                }
                }
                if(aaaa[i] != bbbb[i] && cccc[i] == bbbb[i] && aaaa[i] != cccc[i]){
                if(cc[cccc[i]] > bb[bbbb[i]]){
                for(int j = 1; j <= p; j++){
                    if(aaaa[j] == xyz[j])
                        f[1] == 1;
                    if(cccc[j] == xyz[j])
                        f[3] == 3;
                }
                if(sum < g && f[1] == 0){
                        ans += aa[i];
                        xyz[++p] = i;
                        sum++;
                }
                if(cnt < g && f[3] == 0){
                        ans += cc[i];
                        xyz[++p] = i;
                        cnt++;
                }
                }
                else{
                for(int j = 1; j <= p; j++){
                    if(aaaa[j] == xyz[j])
                        f[1] == 1;
                    if(bbbb[j] == xyz[j])
                        f[2] == 2;
                }
                if(sum < g && f[1] == 0){
                        ans += aa[i];
                        xyz[++p] = i;
                        sum++;
                }
                if(num < g && f[2] == 0){
                        ans += bb[i];
                        num++;
                        xyz[++p] = i;
                }

                }
            }if(aaaa[i] != bbbb[i] && cccc[i] != bbbb[i] && aaaa[i] == cccc[i]){
                if(aa[aaaa[i]] > cc[cccc[i]]){
                for(int j = 1; j <= p; j++){
                    if(aaaa[j] == xyz[j])
                        f[1] == 1;
                    if(bbbb[j] == xyz[j])
                        f[2] == 2;}
                if(sum < g && f[1] == 0){
                        ans += aa[i];
                        xyz[++p] = i;
                        sum++;
                }
                if(num < g && f[2] == 0){
                        ans += bb[i];
                        num++;
                        xyz[++p] = i;
                }
                else{
                    for(int j = 1; j <= p; j++){
                    if(bbbb[j] == xyz[j])
                        f[2] == 2;
                    if(cccc[j] == xyz[j])
                        f[3] == 3;
                }
                if(num < g && f[2] == 0){
                        ans += bb[i];
                        xyz[++p] = i;
                }
                if(cnt < g && f[3] == 0){
                        ans += cc[i];
                        cnt++;
                        xyz[++p] = i;
                }
                }
            }
            }
            }
        }
            */
        for(int i = 1; i <= n; i++){
            d = max(a[i], b[i]);
            d = max(d, c[i]);
            if(d == a[i]){
                if(sum < g){
                    sum++;
                    ans += a[i];
                }
                else{
                    aaa(b[i],c[i]);
                }
            }
            if(d == b[i]){
                if(num < g){
                    num++;
                    ans += b[i];
                }
                else{
                    bbb(a[i], c[i]);
                }
            }
            if(d == c[i]){
                if(cnt < g){
                    cnt++;
                    ans += c[i];
                }
                else{
                    ccc(a[i], b[i]);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
