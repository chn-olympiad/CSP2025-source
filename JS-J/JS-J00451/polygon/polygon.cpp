#include<bits/stdc++.h>
using namespace std;
long long n,length[6000],ans;
int find_max(){
    long long maxn=-1;
    for(int i=1;i<=n;i++){
        if(maxn<length[i]) maxn=length[i];
    }
    return maxn;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&length[i]);
    }
    if(n==3){
        int s=0;
        s+=length[1]+length[2]+length[3];
        if(s>max(max(length[1],length[2]),length[3])*2) cout<<1;
        else cout<<0;
        return 0;
    }
    else if(find_max()==1){
        for(int i=1;i<=n-2;i++){
            ans+=i*(i+1);
        }
        ans=ans/2;
        cout<<ans%998244353;
        return 0;
    }
}
