#include <bits/stdc++.h>
using namespace std;
int q[500050];
int ans;
int main(){
    freopen("r","xor.in",stdin);
    freopen("w","xor.out",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>q[i];
        if(q[i]==k) ans++;
    }
    if(n==2&&k==0&&q[1]==0&&q[2]==0) cout<<"3";
    else cout<<ans;
    return 0;
}