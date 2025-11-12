#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,b;
    int a[5005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n-1);
    for(int i=0;i<n-2;i++){
        for(int j=i+2;j<n;j++){
            if(a[i]+a[i+1]>a[j]){
                ans=ans+i+1;
            }else{
                for(int y=i;y>=0;y--){
                    int b=b+a[y-1];
                    if(b+a[i]+a[i+1]>a[j]){
                        ans=ans+i;
                        break;
                    }
                }
            }
        }
    }
    ans=ans%998244353;
    cout<<ans;
    return 0;
}
