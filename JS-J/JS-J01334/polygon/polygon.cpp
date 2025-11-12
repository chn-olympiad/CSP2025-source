#include <bits/stdc++.h>
using namespace std;
int a[8888];
int b[8888];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        int ma=0;
        for (int j=i;j<n;j++){
            if (b[j]>ma) {
                ma=b[j];
            }
        }
        a[i]=ma;
    }
    int cnt=0;
    for (int i=n;i>=1;i--){
        for (int j=i-1;j>=1;j--){
            for (int k=j-1;k>=1;k--){
                if (2*a[i]<a[i]+a[j]+a[k]) cnt++;
            }
        }
    }
    return 0;
}
