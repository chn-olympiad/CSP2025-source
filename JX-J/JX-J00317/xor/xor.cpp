#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5+10;
long long a[N],k,n;
long long qj(long long x,long long y){
    long long ans=0;
    for(long long i=x;i<=y;i++){
        ans=(ans^a[i]);
    }
    return ans;
}
long long D(long long b,long long e){
    long long ans=0;
    for(long long i=b;i<=e;i++){
        for(long long j=i;j<=e;j++){
            long long qz=qj(i,j);
            if(qz==k){
                ans=1;
                return ans+D(j+1,e);
            }
        }
    }
    return 0;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<D(1,n);
    return 0;
}
