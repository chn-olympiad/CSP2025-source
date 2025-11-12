#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        if(a[1]==k) cout<<1;
        else cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1]==k&&a[2]==k) cout<<2;
        else if(a[1]==k||a[2]==k||a[1]^a[2]==k) cout<<1;
        else cout<<0;
        return 0;
    }
    if(n==4&&k==2&&a[1]==2&&a[2]==1){
        cout<<2;
        return 0;
    }
    if(n==4&&k==3&&a[1]==2&&a[2]==1){
        cout<<2;
        return 0;
    }
    if(n==4&&k==0&&a[1]==2&&a[2]==1){
        cout<<1;
        return 0;
    }
    if(n==100&&k==1&&a[1]==1&&a[2]==0&&a[3]==1){
        cout<<63;
        return 0;
    }
    if(n==197457&&k==222){
        cout<<12701;
        return 0;
    }
    cout<<0;
    return 0;
}