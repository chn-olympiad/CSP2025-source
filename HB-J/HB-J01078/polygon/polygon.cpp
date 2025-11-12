#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void f(int cnt,int cnt1,int maxx,int x){
    if(x>n){
        if(cnt1>=3&&cnt>maxx*2){
            ans=(ans+1)%998244353;
        }
        return;
    }
    f(cnt+a[x],cnt1+1,max(maxx,a[x]),x+1);
    f(cnt,cnt1,maxx,x+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f(0,0,0,1);
    cout<<ans<<endl;
    return 0;
}
