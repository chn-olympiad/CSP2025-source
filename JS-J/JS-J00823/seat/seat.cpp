#include<bits/stdc++.h>
using namespace std;
int num[105],n,m,r,ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    num[1]=r;
    for(int i=2;i<=n*m;i++){
        cin>>num[i];
    }
    sort(&num[1],&num[n*m]+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(num[i]==r){
            ans=i;
            break;
        }
    }
    if(n==1){
        cout<<ans<<" "<<1;
        return 0;
    }
    if(m==0){
        cout<<1<<m;
    }
    int x=(ans+n-1)/n;
    cout<<x<<" ";
    if(x%2==0){
        if(ans%n==1){
            cout<<n;
        }
        else{
            cout<<n+1-(ans%n);
        }
    }
    else{
        if(ans%n==0){
            cout<<n;
        }
        else{
            cout<<ans%n;
        }
    }
    return 0;
}
