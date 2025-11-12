#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int num[100005][3];
int onswitch[100005][3];
int job[3][100005];

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T --) {
        int n;
        cin>>n;
        int ans = 0;
        int tot1 = 0,tot2 = 0,tot3 = 0;
        for(int i = 1;i<=n;i++) {
            cin>>num[i][0]>>num[i][1]>>num[i][2];
            int maxn = max(num[i][0],max(num[i][1],num[i][2]));
            onswitch[0][i] = maxn - num[i][0];
            onswitch[1][i] = maxn - num[i][1];
            onswitch[2][i] = maxn - num[i][2];
            if(num[i][0] > max(num[i][1],num[i][2])) {
                job[0][++tot1] = i;
                ans += num[i][0];
            }
            else if(num[i][1] > max(num[i][2],num[i][0])) {
                job[1][++tot2] = i;
                ans += num[i][1];
            }
            else if(num[i][2] > max(num[i][1],num[i][0])) {
                job[2][++tot3] = i;
                ans += num[i][2];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
