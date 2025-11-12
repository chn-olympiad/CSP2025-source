#include<bits/stdc++.h>
using namespace std;
struct s{
    int l,r;
}v[1000005];
int a[1000005],n,k,m,f=0,w[1000005],l=0;
int main(){
    reopen("xor.in",stdin);
    freopen("xor.out",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1){
        if(a[1]==0)cout<<1;
        else cout<<0;
        return 0;
    }
    if(a[1]==a[2]){
        if(a[1]==k)cout<<2;
        else cout<<1;
        return 0;
    }
    if(a[1]==k||a[2]==k)cout<<1;
    else cout<<0;
}
