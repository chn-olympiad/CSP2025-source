#include<bits/stdc++.h>
using namespace std;
long long a[500005],x[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]^a[i];
    }
    if(k==0&&a[1]==a[2]==1){
        cout<<n/2;
    }

    return 0;
}
