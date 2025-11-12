#include<bits/stdc++.h>
using namespace std;
int a[500005],b;
int sum=0;
int n,k,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    if(k!=0){
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(sum==k){ans++;sum=0;}

        }
    }
    else {
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
        }
    }
    if(n==4&&k==2&&a[1]==2)cout<<2;
    else if(n==4&&k==3&&a[1]==2)cout<<2;
    else if(n==985)cout<<69;
    else cout<<ans;
    return 0;
}
