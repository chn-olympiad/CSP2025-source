#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m, jsq = -1, xr;
    cin >> n >> m;
    int l = 0, h = 1;
    int zw = n * m;
    vector<int> vt(zw);
    vector<int> vt2(zw);
    for (int i = 0; i < zw; i++) {
        cin >> vt[i];
        vt2[i] = vt[i];
    }
    xr = vt[0];
    sort(vt.begin(), vt.end(), greater<int>());
    while(h < n) {
        l++;
        if (l > m) {
            l--;
            h++;
            jsq++;
            if (vt[jsq] == xr) {
                break;
            }
            while(1) {
                l--;
                if (l == 0) {
                    l++;
                    h++;
                    if (h > n) {
                        h--;
                        break;
                    }
                    break;
                }
                jsq++;
                if (vt[jsq] == xr) {
                    break;
                }
            }
        }
        jsq++;
        if (jsq > zw) {
            jsq--;
            break;
        }
        if (vt[jsq] == xr) {
            break;
        }
    }
    cout << h << " " << l;


    return 0;
}
