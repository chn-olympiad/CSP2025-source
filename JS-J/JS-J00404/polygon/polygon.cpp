#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,a[5500],jis=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<(1<<n);i++){
        long long h=0,d=0,m=i,ji=0;
        for(int j=1;j<=n;j++){
            if(m&1){
                d=max(d,a[j]);
                h+=a[j];
                ji++;
            }
            m>>=1;
        }
        if(h>d*2 && ji>=3) jis++;
    }
    cout<<jis;
    return 0;
}
