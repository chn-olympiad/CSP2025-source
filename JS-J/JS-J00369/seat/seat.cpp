#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int sum=1;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int xr=a[1];
    for(int i=2;i<=n*m;i++){
        if(a[i]>xr) sum++;
    }
    int cnt=sum%n;
    if(cnt==0) {
        ans=sum/n;
        cnt=n;
    }else{
        ans=sum/n+1;
    }
    if(ans%2!=0){
        cout<<ans<<' '<<cnt;
    }else{
        cout<<ans<<' '<<n-cnt+1;
    }
    return 0;
}