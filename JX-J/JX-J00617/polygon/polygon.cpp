#include<bits/stdc++.h>
using namespace std;
int n,a[5010],m=-1,s=10000000;
long long sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m=max(m,a[i]);
        s=min(s,a[i]);
    }
    if(n<=2){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(m==1||m<s*2){
        for(int i=3;i<=n;i++){
                long long p=1;
            for(int j=1;j<=i;j++){
                p*=(n+1-j);
                p/=j;
                p%=998244353;
            }
        sum+=p;
        sum%=988244353;
        }
    }
    cout<<sum;
    return 0;
}
