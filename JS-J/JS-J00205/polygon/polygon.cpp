#include<bits/stdc++.h>
using namespace std;
int a[5001]={};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int k=3;k<=n;k++){
        for(int i=k;i<=n;i++){
            int cnt=0;
            for(int j=i-1;j>=i-k+1;j--){
                cnt+=a[j];
            }
            if(cnt>a[i])ans++;
        }
    }
    cout<<ans%998244353;
    return 0;
}
