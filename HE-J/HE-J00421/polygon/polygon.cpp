#include<bits/stdc++.h>
using namespace std;
int n, m, a[5005],ans,cnt = 0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans = max(a[i], a[i-1]);
    }for(int i = 3; i <= n; i++){
        if(a[i] + a[i - 1] + a[i - 2] > ans){
            cnt ++;
        }if(a[i] + a[i - 1] + a[i - 2]+a[i-3] > ans){
            cnt ++;
        }if(a[i] + a[i - 1] + a[i - 2]+a[i - 3] + a[i - 4] > ans){
            cnt ++;
        }if(a[i] + a[i - 1] + a[i - 2]+a[i - 3] + a[i - 4] + a[i - 5] > ans){
            cnt ++;
        }if(a[i] + a[i - 1] + a[i - 2]+a[i - 3] + a[i - 4] + a[i - 5] + a[i - 6]> ans){
            cnt ++;
        }if(a[i] + a[i - 1] + a[i - 2]+a[i - 3] + a[i - 4] + a[i - 5] + a[i - 6] + a[i - 7]> ans){
            cnt ++;
        }if(a[i] + a[i - 1] + a[i - 2]+a[i - 3] + a[i - 4] + a[i - 5] + a[i - 6] + a[i - 7] + a[i - 8]> ans){
            cnt ++;
        }

    cout << cnt%353;
    }
}
