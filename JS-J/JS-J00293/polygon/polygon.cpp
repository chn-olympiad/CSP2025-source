#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int mod=998244353;
int a[maxn],sum[maxn],mx[maxn],mul[maxn];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    bool f=false;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++){
        mul[i]=(mul[i-1]*i)%mod;
    }
    for(int i=1; i<=n; i++){
        sum[i]=sum[i-1]+a[i];
        mx[i]=max(mx[i-1],a[i]);
    }
    if(n==3){
        if(sum[n]>=2*mx[n]){
            cout<<1<<endl;
            return 0;
        }else{
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
