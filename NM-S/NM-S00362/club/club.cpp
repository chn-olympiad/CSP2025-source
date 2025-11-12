#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=3;j++){
                cin >> a[i][j];
            }
            int ans = a[i][1] + a[i][2] + a[i][3];
            ans = max(ans,a[i][2]);
        }



        cout << ans << endl;

    }
    return 0;
}
