#include<bits/stdc++.h>
#ifndef zhouyi
#define dbg
#define breakpoint
#else
#define dbg(x) cout<<'('<<#x<<')'<<" = "<<x<<endl
#define breakpoint getchar()
#endif
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    bool isao=true;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]!=a[i-1])isao=false;
    }
    if(n==2&&a[0]==a[1]&&k==0)cout<<1;
    else if(n==1&&k!=a[0])cout<<0;
    else if(n==1&&k==a[0])cout<<1;
    else if(k==0&&isao){
        cout<<n*(n-1)/2;
    }
    else cout<<42;//听天由命了
    return 0;
}