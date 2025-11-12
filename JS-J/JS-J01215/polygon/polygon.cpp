#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+9;
long long n;
long long a[maxn];
bool cmp(long long x,long long y){
    return x<y;
}
long long C(long long k,long long m){
    long long K_M=1,KM=1;
    for(int i=k;i<=m;i++){
        K_M*=i;
    }
    for(int i=1;i<=m-k;i++){
        KM*=i;
    }
    return (K_M/KM)%998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    long long maxa=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    if(n<=2){
        cout<<0;
        return 0;
    }
    if(n==3){
        sort(a+1,a+4,cmp);
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    long long ans=0;
    if(maxa==1){
        for(long long i=3;i<=n;i++){
           ans+=C(i,n);
           ans%= 998244353;
        }
        cout<<ans%998244353;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
