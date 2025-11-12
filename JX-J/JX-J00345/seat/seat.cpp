#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            int x;cin>>x;
            if(x>k) cnt++;
        }
    }
    int mod=(cnt-1)%n+1;
    int c=(cnt-1)/n+1,r=(c%2?mod:n-mod+1);
    cout<<c<<" "<<r;
    return 0;
}