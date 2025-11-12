#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[110],R;
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(LL i=1;i<=n*m;i++){
        if(a[i]==R){
            LL tmp=i/n+(i%n!=0);
            if(tmp%2!=0){
                LL ans=i%n;
                if(ans==0){
                    cout<<tmp<<" "<<n;
                }
                else{
                    cout<<tmp<<" "<<ans;
                }
            }
            else{
                if(i%n==0){
                    cout<<tmp<<" "<<n-i%n;
                }
                else{
                    cout<<tmp<<" "<<n-i%n+1;
                }
            }
            return 0;
        }
    }
    return 0;
}
