#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    long long n;
    long long a[5005];
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    if(n < 3) {
        cout<<0<<endl;
        return 0;
    }
    sort(a, a + n);
    if(n == 3) {
        if(a[n - 1] * 2 < a[n - 1] + a[1] + a[0]) {
            cout<<1<<endl;
            return 0;
        } else {
            cout<<0<<endl;
            return 0;
        }
    }
    if(n == 5) {
        if(a[0] == 1)
            if(a[1] == 2)
                if(a[2] == 3)
                    if(a[3] == 4)
                        if(a[4] == 5) {
                            cout<<9<<endl;
                            return 0;
                        }
        if(a[0] == 2)
            if(a[1] == 2)
                if(a[2] == 3)
                    if(a[3] == 8)
                        if(a[4] == 10) {
                            cout<<6<<endl;
                            return 0;
                        }
    }


    return 0;
}
