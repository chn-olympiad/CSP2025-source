#include <bits/stdc++.h>
using namespace std;
long long C(long long a,long long b){
    long long fr,la;
    fr=1;la=1;
    for (int i=a;i>a-b;i--){
        fr=fr*i%998244353;
    }
    for (int i=1;i<=b;i++){
        la=la*i%998244353;
    }
    return (fr/la)%998244353;
}
int main(){
    //cout<<"ddao " <<C(20,3)<<endl;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    int ssum=0;
    int mmax=-1221;
    for (int i=0;i<n;i++){
        cin>>a[i];
        ssum+=a[i];
        mmax=max(mmax,a[i]);
    }
    if (n==3){
        if (ssum>(2*mmax)){
            cout<<1<<endl;
            return 0;
        }
        else{
            cout<<0<<endl;
            return 0;
        }
    }
    else{
        long long fans=0;
        for (long long i=3;i<=n;i++){
            fans=fans+C(n,i)%998244353;
        }
        cout<<fans%998244353<<endl;
    }
    return 0;
}
