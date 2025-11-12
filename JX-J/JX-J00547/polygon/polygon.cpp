#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],sum,ddf,t,f[100][1000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]+a[3]>a[n]*2)
            cout<<1;
        else
            cout<<0;
    }
    if(n<=20){
        ddf=sum-a[n]*2;
        for(int i=n;i>=1;i--){
            for(int j=1;a[j]<=ddf;j++){
                f[i][j]=f[i][ddf-a[j]]+1;
            }
        }
    }
    cout<<f[n][ddf];
    return 0;
}
