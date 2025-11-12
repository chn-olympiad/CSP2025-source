#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int n,k;
int yhh(int l,int r){
    if(l==r){
        return a[l];
    }
    int x=a[l]^a[l+1];
    for(int i=l+2;i<=r;i++){
        x=x^a[i];
    }
    return x;
}
int cha(int x,int now){
    if(x==n){
        return now;
    }
    for(int i=x+1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(yhh(i,j)==k){
                return cha(j,now+1);
            }
        }
    }
    return now;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<cha(0,0);
    return 0;
}
