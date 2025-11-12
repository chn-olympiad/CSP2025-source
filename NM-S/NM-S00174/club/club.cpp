#include<bits/stdc++.h>
using namespace std;
const int N = 10e6+10;
int t, n;
int ans;
int c[5];
int a[N][5];
int main(){
        freopen("input.in","r",stdin);
        freopen("output.out","w",stdout);
        int maxn = -1;
        cin >> t;
        for(int i = 0;i < t;i++){
                ans = 0;
                cin >> n;
                int w = n/2;
                for(int j = 0;j < n;j++){
                        for(int k = 0;k < 3;k++){
                                cin >> a[j][k];
                        }
                }
                for(int j = 0;j < n;j++){
                    maxn = -1;
                    for(int k = 0;k < 3;k++){
                        if(a[j][k] > maxn){
                            maxn = a[j][k];
                        }
                    }
                    ans += maxn;
                }
                cout << ans;
        }
        return 0;
}
