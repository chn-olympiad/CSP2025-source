#include<bits/stdc++.h>
using namespace std;
long long n,a[5555],cnt1,sum,m=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*(max(a[1],max(a[2],a[3])))){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(cnt1==n){
        for(int i=3;i<=n;i++){
            long long cum=1;
            for(int j=n-i;j>=1;j--){
                cum*=(j+i);
                cum%=m;
            }
            sum+=cum;
            sum%=m;
        }
        cout<<sum%m;
        return 0;
    }
    return 0;
}
