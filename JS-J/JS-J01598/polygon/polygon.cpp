#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
long long ans,f[20][2000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    if(n==3){
        cout << (a[0]+a[1]>a[2]);
        return 0;
    }
    for(int i=0;i<n-1;i++){
        if(i!=0){
            for(int j=1;j<2000;j++){
                f[i][j]=f[i-1][j];
            }
            for(int j=1;j<2000;j++){
                if(f[i-1][j])f[i][j+a[i]]+=f[i-1][j];
            }
        }
        f[i][a[i]]++;
    }
    for(int i=2;i<n;i++){
        for(int j=a[i]+1;j<2000;j++){
            ans+=f[i-1][j];
            ans%=998244353;
        }
    }
    cout << ans;
    return 0;
}
