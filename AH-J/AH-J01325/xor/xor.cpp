#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N+10],l[N],r[N];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,f=0;
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (a[i] != 1) {
            f=1;
        }
    }

    if (k == 0 && f=0) {
        cout << n << endl;
        return 0;
    }

    int h=0;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int num=0;
            for (int g=i;g<=j;g++) {
                num=a[g]^num;
            }
            if (num == k) {
                l[h]=i;
                r[h]=j;
                h++;
            }
        }
    }
    int max_h=0;
    for (int i=0;i<h;i++) {
        int cnt=1;
        for (int j=i+1;j<=h;j++) {
            if (r[i] < r[j]) {
                    cout << r[i] << " " <<r[j] << endl;
                cnt++;
            }
        }
        max_h=max(cnt,max_h);
    }
    cout << max_h << endl;
}
