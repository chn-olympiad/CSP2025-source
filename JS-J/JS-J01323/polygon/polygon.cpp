#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],f=0;
const int m=998244353;
int A(int n){
    int cnt=1;
    for(int i=1;i<=n;i++){
        cnt*=i;
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if(i>1){
            if(a[i]!=a[i-1]||(a[i]==a[i-1]&&a[i]!=1))f=1;
        }
    }
    if(n<=3){
        if(max({a[1],a[2],a[3]})*2<a[1]+a[2]+a[3])cout<<1;
        else cout<<0;
        return 0;
    }else{
        if(f==0){
            int ans=0;
            for(int i=3;i<=n;i++){
                ans+=(A(n)/A(n-i))/A(i);
                ans%=m;
            }
            cout<<ans;
            return 0;
        }

    }
    return 0;
}
