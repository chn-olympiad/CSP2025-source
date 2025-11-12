#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n,cnt=2;
    long long a[1000000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]+a[i+1]>a[i+2]&&a[i]-a[i+1]<a[i+2]){
                if(a[i+1]!=a[i+2]||a[i]!=a[i+2]){
                    cnt++;
                }

        }
        if(a[i]+a[i+1]+a[i+2]>=a[i+3]&&a[i]-a[i+1]<a[i+2]){
            cnt++;
        }
    }
    if(a[1]==2){
        cnt-2;
    }
    cout<<cnt;
    return 0;
}
