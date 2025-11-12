#include<bits/stdc++.h>
using namespace std;
long long q[6000];
long long f(long long a){
    long long t=0;
    for(long long i=a;i>=2;i--){
        t+=i*(i-1);
    }
    return t/2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,p=0,h=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>q[i];
    }
    sort(q+1,q+n+1);
    if(n==3){
        if(q[1]+q[2]>2*q[3]){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    for(long long i=3;i<=n;i++){
        for(long long cnt=1;cnt<=i-2;cnt++){
                h=q[cnt];
            for(long long j=cnt+1;j<=i-1;j++){
                if(h+q[j]>q[i]){
                    p+=f(i-j+1)+i-j+1;
                    break;
                }
            }
        }
    }
    cout<<p%998244353;
    return 0;
}
