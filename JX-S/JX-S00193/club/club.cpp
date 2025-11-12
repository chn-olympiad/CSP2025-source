#include<bits/stdc++.h>
using namespace std;
const int MAXN = 84;

int t;

struct node{
    int o1,o2,o3;
};


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> t;


    while(t--){

        node a[MAXN];
        int n;

        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i].o1 >> a[i].o2 >> a[i].o3;

        }

        int z = n/2 ;
        long long dp[z][z][z];


        for(int i = 0;i <= z;i++){
            for(int j = 0;j <= z;j++){
                for(int x = 0;x <= z;x++){
                    dp[i][j][x] = 0;
                }
            }
        }

        cout << 1;
        for(int i = 1;i <= z;i++){
            for(int j = 1;j <= z;j++){
                for(int x = 1;x <= z;x++){
                    for(int p = 0;p < 1;p++){
                        dp[i][j][x] = max(dp[i][j][x],dp[i-1][j][x]+a[p].o1);
                    }

                }
            }
        }

        long long ans = 0;
        for(int i = 1;i <= z;i++){
            for(int j = 1;j <= z;j++){
                for(int x = 1;x <= z;x++){
                    ans = max(dp[i][j][x],ans);
                }
            }
        }

        cout << ans << "\n";

    }


    return 0;
}

