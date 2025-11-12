#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }else if(n==3){
        sort(a+1,a+1+n);
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    return 0;
}
