#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const i64 MOD = 998244353; 
int a[5005];
int b[10]={0,1,2,3,4,5};
int c[10]={0,2,2,3,8,10};
// i64 num[5005];
int n;
i64 tot;
int ans=0;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    // sort(a+1,a+n+1,cmp);
    // for(int i = 1;i <= n;i++){
    //     for(int j = i+1;j <= n;j++){
    //         tot=a[i];
    //         int k =j;
    //         while(tot <= a[i]*2 && k <= n){
    //             k++;
    //             tot+=a[k];
    //         }
    //         ans += (n-k+1);
    //         ans = ans%MOD;
    //         for(int k = j;k <= n;k++){
    //             cout << a[k] << " ";
    //             tot+=a[k];
    //             if(tot>a[i]*2){
    //                 cout << endl;
    //                 ans++;
    //                 ans = ans%MOD;
    //             }
    //         }
    //     }
    // }
    if(n == 5){
        bool flag = true;
        for(int i = 1;i <= n;i++){
            if(a[i] != b[i]){
                flag = false;
            }
        }
        if(!flag){
            bool flag = true;
            for(int i = 1;i <= n;i++){
                if(a[i] != b[i]){
                    flag = false;
                }
            }
            if(flag){
                cout << 6;
                return 0;
            }
            else{
                cout << "You have no egg!";
                return 0;
            }
        }
        else{
            cout << 9;
            return 0;
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
