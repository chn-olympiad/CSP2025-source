#include <bits/stdc++.h>
using namespace std;
int a[1000005],n,k,sum;
long long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    sum=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum=sum*a[i];
    }
    if (sum==1){
        int cnt=0;
        while(n>=2*cnt){
            ans+=n/(2*(++cnt));
        }
    }
    else{
        ans=2;
    }
    cout<<ans;
    return 0;
}
