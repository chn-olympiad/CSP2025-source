#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],n,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=3){
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+1+3);
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    else{
        for(int i=1;i<=n;i++) cin>>a[i];
        b[4]=3;
        for(int i=5;i<=n;i++) b[i]=b[i-1]+i-1;
        for(int i=4;i<=n;i++){
            for(int j=i;j<=n;j++) ans+=b[i];
        }
        cout<<ans;
    }
    return 0;
}
