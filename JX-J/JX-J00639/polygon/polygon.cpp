#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[5005],s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            m=1;
        }
        ll op=1,ops=1;
        for(int j=1;j<=i;j++){
            op*=j;
            ops*=(n-j+1)%998244353;
        }
        s+=(ops/op)%998244353;
        s%=998244353;
    }
    if(!m){
        cout<<s<<endl;
    }

    return 0;
}
