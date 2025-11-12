#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],cnt,flag,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(cnt==a[i]){
            flag=n*m-i+1;
            break;
        }
    }
    if(flag<=n){
        cout<<1<<" "<<flag;
        return 0;
    }
    else{
        sum=(flag-(flag%n))/n;
        if((sum+1)%2==0){
            cout<<sum+1<<" "<<n-flag%n+1;
        }
        else{
            cout<<sum+1<<" "<<flag%n;
        }
    }
    return 0;
}
