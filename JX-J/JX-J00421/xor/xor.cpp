#include <bits/stdc++.h>
using namespace std;
int a[100001]={};
int l,r;
int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,maxn=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        if(a[i]==k){
            cout<<k;
        }else if(maxn<a[i]){
            maxn==a[i];
            cout<<maxn;
        }
    }
    return 0;
}
