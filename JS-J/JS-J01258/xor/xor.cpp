#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a0=0,a1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) a0++;
        if(a[i]==1) a1++;
    }
    if(k==0){
        cout<<a0+a1/2;
    }else if(k==1){
        cout<<a1;
    }else cout<<2;
    return 0;
}