#include <bits/stdc++.h>

using namespace std;
int t,n;

int a[100001],b[100001],c[100001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                for(int o = 1;o <= n;o++) {
                    if(i + j + o == n && i <= n/2 && j <= n/2 && o <= n/2) {
                        ans = max(ans,a[i] + b[j] + c[o]);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
