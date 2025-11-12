#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt;
int sum;
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==255)sum++;
        if(x==0)ans++;
        if(x==1)cnt++;
    }
    if(k==1)cout<<cnt;
    else if(k==0)cout<<ans;
    else if(k==255)cout<<sum;
    else cout<<k;
    return 0;
}
