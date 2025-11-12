#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    int a[5055];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(a[i]+a[j]>a[k]&&a[j]+a[k]>a[i]&&a[i]+a[j]>a[k]) ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
