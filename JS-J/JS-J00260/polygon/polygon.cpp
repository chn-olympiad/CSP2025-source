#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
int a[5005];
int qzh[5005];
int cnt;
void v3(){
    for(int i = 1;i<=n-2;i++){
        for(int j = 2;j<=n-1;j++){
            for(int k = 3;k<=n;k++){
                int zh = a[i]+a[j]+a[k];
                int maxn = max(i,max(j,k));
                if(zh>maxn*2) ans++;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int maxa = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        maxa = max(maxa,a[i]);
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n == 3){
        v3();
        cout<<ans;return 0;
    }
    if(maxa == 1){

        for(int i = 3;i<=n;i++){
            ll fm = 1;
            ll m = 1;

            for(int j = i+1;j<=n;j++){
                m*=j;
            }
            for(int j = 1;j<=n-i;j++){
                fm*=j;
            }
        ans+=m/fm;
        }
    }
    cout<<ans%998244353;
    return 0;
}
