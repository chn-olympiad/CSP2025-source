#include<bits/stdc++.h>
using namespace std;
int n,a[5005],t[5005],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        t[i]=t[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=3;j<=n;j++){
            if(t[j]-t[i-1]>a[j]*2){
                  cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
