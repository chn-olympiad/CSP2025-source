#include<bits/stdc++.h>
using namespace std;

long long a[5010],n,ans=0,cnt=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(n==1){
            cout<<'0';
        }
        if(n==2){
            cout<<'0';
        }
        if(n==3){
            if(a[1]+a[2]<a[3]){
                cout<<'0';
            }
            else if(a[2]+a[3]<a[1]){
                cout<<'0';
            }
            else if(a[1]+a[3]<a[2]){
                cout<<'0';
            }
            else cout<<'1';
        }
        return 0;
    }
    for(int i=3;i<=n;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=i-1;l++){
                cnt+=a[j+l-1];
            }
            if(cnt>a[j+i]) ans++;
        }
    }
    ans=ans%998%244%353;
    cout<<ans;

    return 0;
}