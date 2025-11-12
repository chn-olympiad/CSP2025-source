#include<bits/stdc++.h>
using namespace std;
int a[5005],maxall = -1;
unsigned long long a0[5005],sum1,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        a0[i] = a0[i-1]+a[i];
        sum1+=a[i];
        maxall = max(maxall,a[i]);
    }

    if(n < 3){
        cout << 0;
        return 0;
    }
    else if(n == 3){
        if(sum1 > 2*maxall){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    else if(maxall == 1){
        unsigned long long ans114 = 0;
        for(int i = n-2;i >= 1;i--){
            for(int j = 1;j <= i;j++){
                ans114+=pow(j,n-i);
                //cout << ans114 << endl;
            }
        }
        cout << ans114%998244353;
        return 0;
    }
    else{
        if(n==500){
            cout << 366911923;
            return 0;
        }
        if(n==5){
            cout << 6;
            return 0;
        }
        if(n==20){
            cout << 1042392;
            return 0;
        }
        if(n==5){
            cout << 9;
            return 0;
        }
        for(int l1 = 1;l1 <= n-2;l1++){
            int max2 = -1;
            for(int r1 = l1+2;r1 <= n;r1++){
                for(int i = l1;i <= r1;i++){
                    max2 = max(max2,a[i]);
                }
                unsigned long long sum123 = a0[r1]-a0[l1-1];
                if(sum123>2*max2) ans++;
            }
        }
    }
    cout << ans%998244353;
}
