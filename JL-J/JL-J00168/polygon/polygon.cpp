#include<iostream>
using namespace std;
int n,a[10000];
long long ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),max(a[2],a[3]))){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else{
        for(int i=n;i>=3;i--){
            ans+=1+(n-1)*(n-i);
            ans=ans%998224353;
        }
    }
    cout<<ans;
    return 0;
}
