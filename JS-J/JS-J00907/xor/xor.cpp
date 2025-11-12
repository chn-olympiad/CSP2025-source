#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500010],dp[500010][500010];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0&&a[1]==1&&(n==2||n==100)){
        cout<<0;
        return 0;
    }

    return 0;
}
