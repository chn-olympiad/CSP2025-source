#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=998244353;
int b[N],a[N],dp[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    int cnt=0;
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(b[3]>=a[3]*2){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    for(int i=1;i<=n-3;i++){
        for(int j=i+3;j<=n;j++){
            int t=b[j]-b[i-1];
            if(t>a[j]*2){
                cnt++;
            }
            if(t-a[j-1]+a[j+1]>a[j+1]*2&&j!=n){
                cnt++;
            }
            if(t-a[j-2]+a[j+1]>a[j+1]*2&&j!=n){
                cnt++;
            }
            if(t-a[j-3]+a[j+1]>a[j+1]*2&&j!=n){
                cnt++;
            }
            if(t-a[j+1]+a[j-1]>a[j]*2&&j-i>=4&&j!=n){
                cnt++;
            }
            if(t-a[i+1]+a[i-1]>a[j]*2&&j-i>=4&&i==1){
                cnt++;
            }
            if(t-a[i-1]+a[i+1]>a[j]*2&&i!=1){
                cnt++;
            }
        }
    }
    cout<<cnt%M;
    return 0;
}
