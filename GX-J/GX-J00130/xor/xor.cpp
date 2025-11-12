#include <bits/stdc++.h>

using namespace std;

int n,k,q=0,num[(int)5e5+10],last=0,sum;

int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> num[i];
    }
    sum=num[last];
    bool flap=false;
    for (int i=0;i<n;i++) {
        if (i>0&&flap) {
            sum ^= num[i];
        }
        if (sum==k) {
            q++;
            last++;
            sum=num[last];
            flap=false;
            continue;
        }
        flap=true;
    }
    if (flap) {
        q++;
    }
    cout << q;
    return 0;
}
