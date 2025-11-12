#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5010],q[5010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q[i]+=a[i];
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<i;j++)if(q[j]==a[i])ans+=(j-i+1);
    }
    cout<<ans%998244353;
}
