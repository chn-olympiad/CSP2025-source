#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,a[500010],ans=0,cnt;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cnt=a[1];
    for(int i=2;i<=n;i++){
        if(cnt==k){
            ans++;
            cnt=a[i];
            continue;
        }
        cnt=cnt^a[i];
    }
    if(cnt==k){
        ans++;
    }
    cout<<ans;
    return 0;
}
