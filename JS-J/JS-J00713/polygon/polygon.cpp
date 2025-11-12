#include<bits/stdc++.h>
using namespace std;

const int N=5010;
int n,a[N],i,j,ma,sum;
long long ans,tmp;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(n==3){
        ma=max(max(a[1],a[2]),a[3]);
        sum=a[1]+a[2]+a[3];
        cout<<(sum>(2*ma));
    }else if(ma==1){
        for(i=3;i<=n;i++){
            tmp=1;
            for(j=1;j<=i;j--){
                tmp*=n-i+2-j;
                tmp%=998244353;
            }
            ans+=tmp;
            ans%=998244353;
        }
        cout<<ans;
    }
    return 0;
}
