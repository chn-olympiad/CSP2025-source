#include <iostream>
#include <algorithm>
using namespace std;
int t,n,a[100009][5],s[100009],d[100009],m[5],sum;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++) {
                cin >> a[i][j];
                if(a[i][j] > s[i]) {
                    s[i] = a[i][j];
                    d[i] = j;
                }
            }
            m[d[i]] += 1;
        }
        if(m[1] == n) {
            sort(s + 1,s + n + 1);
            sum = s[n] + s[n - 1];
        }
        else if((m[1] <= n/2) && (m[2] <= n/2) && (m[3] <= n/2)) {
            for(int i = 1;i <= n;i++) {
                sum += s[i];
            }
        }
        else {
            for(int i = 1;i <= n;i++) {
                for(int j = i + 1;j <= n;j++) {
                    if(d[i] == d[j]) {
                        if(s[i] < s[j]) {
                            a[i][d[i]] = 0;
                            s[i] = 0;
                            for(int k = 1;k <= 3;k++) {
                                if(a[i][k] > s[i]) {
                                    s[i] = a[i][k];
                                    d[i] = k;
                                }
                            }
                        }
                        else {
                            a[i][d[i]] = 0;
                            s[i] = 0;
                            for(int k = 1;k <= 3;k++) {
                                if(a[i][k] > s[i]) {
                                    s[i] = a[i][k];
                                    d[i] = k;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 1;i <= n;i++) {
                sum += s[i];
            }
        }
        cout << sum;
    }
    return 0;
}
