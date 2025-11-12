#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int a[5005];

int dp[5005][5005];
int ans;
int main(){
    freopen("polygon.in","r", stdin);
    freopen("polygon.out","w", stdout);
    int n;
    cin >> n;
    bool ai1 = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] != 1){
            ai1 = false;
        }
    }//dp[i][j] xuan i genmugun, de fanganshu
    if(ai1 == true){
        ans = 0;
        for (int i = 3; i <= n; i++){
            int c = 1;
            for(int j = n; j > (n - i); j--){
                c *= j;
            }
            for(int j = 1; j <= i; j++){
                c /= j;
            }
            ans += c;
        }

    }
    else{
        // for (int i = 3; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
            
        //     }
        // }
        // for (int i = 3; i <= n; i++){
        //     for (int j = 1; j <= i; j++){
        //         for (int k = 1; k <= n; k++) {

        //         }
        //     }
        // }
        if(n == 3){
            //for(int i = 2; i <= n; i++){
            //int i = n;
               // for (int j = 1; j <= i; j++){
               //     for (int k = i + 1; k <= i; k++){
               //         int maxx;
                //        if(n == 2){
                //             maxx = max(a[j], a[k]);
                //        }else{
                //             maxx = max(a[j], max(a[k], a[k + 1]));
                //        }
                //        if((a[j] + a[k] + a[k + 1] )> maxx * 2){
                //            ans++;
                //        }
                //    }
                //}
            //}
            int maxx = max(a[1], max(a[2], a[3]));

            if((a[1]+a[2]+a[3]) > maxx * 2) ans++;

        }else{
            for(int i = 3; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    for (int k = j + 1; k <= n; k++){
                        for(int l = k + 1; l <= n; l++){
                            for(int m = l + 1; m <= n; m++){
                                for(int o = m + 1; o <= n; o++){
                                    if(i == 5){
                                        int maxx; 
                                        maxx = max(a[j], max(a[k], max(a[l], max(a[m], a[o]))));
                                        if((a[j] + a[k] + a[l] + a[m]+ a[o])> maxx * 2){
                                            ans++;
                                        }
                                    }
                                }
                                if(i == 4){
                                    int maxx; 
                                    maxx = max(a[j], max(a[k], max(a[l], a[m])));
                                    if((a[j] + a[k] + a[l] + a[m])> maxx * 2){
                                        ans++;
                                    }
                                }
                            }
                      
                        }
                           
                    }    
                }  
            }
        }
    }
     cout << ans;
	return 0;
}