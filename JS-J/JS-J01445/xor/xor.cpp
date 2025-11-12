#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k,a[10005],cnt=0,tmp;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=2;
    while(t<=n){
        cnt+=n/t;
        t+=2;
    }
    cout<<cnt;
    return 0;
}
