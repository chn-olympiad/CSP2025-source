#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, num[100005][5], ans=0, cl[4]={0}, out=0, c=1;
        bool fl[100005]={0};
        cin >> n;
        for (int i=1; i<=n; i++) cin >> num[i][1] >> num[i][2] >> num[i][3];
        while (out<n) {
            int big=-1, name=0;
            for (int i=1; i<=n; i++) if (num[i][c]>big&&cl[c]<n/2&&fl[i]==0) {
                big=num[i][c];
                name=i;
            }
            fl[name]=1;
            if (cl[c]<n/2) {
                cl[c]++;
                ans+=big;
                out++;
            }
            c++;
            if (c>3) c=1;
        }
        cout << ans;
    }
    return 0;
}
