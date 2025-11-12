#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10005];
long long f(long long x){
    long long s=1;
    for(int i=n-x+1;i<=n;i++){
        s*=i;
        s%=998244353;
    }
}
long long fa(int a){
    long long s=1;
    for(int i=1;i<=a;i++){
        s*=i;
        s%=998244353;
    }
    return s;
}
long long A(long long a){
    long long s=0;
    for(int i=a;i<=n;i++){
        s+=f(a)%998244353/fa(a);
    }
    return s;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(a[1]+a[2]>a[3]||a[1]+a[3]>a[2]||a[3]+a[2]>a[1]){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }else{
        long long cnt=0;
        for(int i=3;i<=n;i++){
            cnt+=A(i);
        }
        cout<<cnt;
    }
    return 0;
}
