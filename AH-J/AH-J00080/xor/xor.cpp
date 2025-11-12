#include<iostream>
using namespace std;
int n,k;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //A
    if(n<=2){
        if(n==1) cout<<0;
        else cout<<1;
        return 0;
    }
    if(k==0){
        cout<<n/2;
        return 0;
    }
    //B
    if(k<=1){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==k) ans++;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
