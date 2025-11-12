#include<bits/stdc++.h>
using namespace std;
long long he[1000005];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long n;
cin>>n;
long long a[n+1];
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
if(n==3) cout<<1;
else{
    long long j=1;
    for(long long i=3;i<=n;i++){
        j*=i;
    }
    cout<<j;
}

    return 0;
}
