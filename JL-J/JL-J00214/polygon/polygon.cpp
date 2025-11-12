#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++){
        for(int j=2;j<=n-1;j++){
            for(int t=3;t<=n;t++){
                if(a[i]+a[j]>a[t] && a[i]+a[t]>a[j] && a[j]+a[t]>a[i]) sum++;
            }
        }
    }
    cout<<sum;
return 0;
}
