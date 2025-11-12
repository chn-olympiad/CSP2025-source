#include<bits/stdc++.h>
using namespace std;
int n,h,ans=0;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-2;i++){
        for(int j=2;j<=n-1;j++){
            h=0;
            for(int k=i;k<=i+j;k++){
                h+=a[k];
            }
            if(h>2*a[i+j]){
                ans=(ans+1)%908244353;
            }
        }
    }
    cout<<ans;
    return 0;
}
