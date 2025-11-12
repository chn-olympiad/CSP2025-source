#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long f[102][102][102];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;

    while(t --){
        int a[100005][5];

        int n;
        cin >> n;
        for(int j = 0;j <= n;j ++){
            for(int k = 0;k <= n;k ++){
                f[0][j][k] = -1e18;
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int k = 0;k <= n;k ++){
                f[i][0][k] = -1e18;
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                f[i][j][0] = -1e18;
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= 3;j ++){
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= n/2+1;i ++){
            for(int j = 1;j <= n/2+1;j ++){
                for(int k = 1;k <= n/2+1;k ++){
                    if(i+j+k == 3)continue;
                    long long x = f[i-1][j][k];
                    long long y = f[i][j-1][k];
                    long long z = f[i][j][k-1];
                    int s = i+j+k-3;
                    f[i][j][k] = max(max(x+a[s][1],y+a[s][2]),z+a[s][3]);
                }
            }
        }
        long long mx;
        for(int i = 1;i <= n/2+1;i ++){
            for(int j = 1;j <= n/2+1;j ++){
                int k = n + 3 - i - j;
                if(k <= n/2+1){
                    mx = max(mx,f[i][j][k]);
                }

            }
        }
        cout << mx <<endl;
    }
    return 0;
}