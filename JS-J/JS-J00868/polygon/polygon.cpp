#include<bits/stdc++.h>
using namespace std;
int n,a[5555];
long long ans,mod=998244353ll;
inline void f(int x,int loc,long long tot){
    //cout<<x<<" "<<loc<<" "<<tot<<"\n";
    if(x==0){
        int ad=0;
        for(int i=loc;i<=n;++i){
            //cout<<a[i]<<";\n";
            if(a[i]*2<(tot+a[i])){
                ++ad;
            }else{
                break;
            }
        }
        ans+=ad;
        return ;
    }
    for(int i=loc;i<=n-x;++i){
        f(x-1,i+1,tot+a[i]);
    }
    return ;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=2;i<n;++i){
        f(i,1,0);
    }
    ans%=mod;
    printf("%lld",ans);
    return 0;
}
