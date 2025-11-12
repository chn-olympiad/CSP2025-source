#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long cnt=0;
long long a[5001],c[5001],b[5001];
int n,m=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=c[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=i-1;j>=1;j--){
            for(int k=1;k<n-j;k++){
                if(c[i]-c[j]+c[j-k]>a[i]*2){
                    cnt++;
                }
            }
            cnt=cnt%mod;
        }
        cnt=cnt%mod;
    }
    cout<<cnt%mod;
    return 0;
}
