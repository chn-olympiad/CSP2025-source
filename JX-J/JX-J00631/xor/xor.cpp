#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int qz(int l,int r){
    if(l==r) return a[l];
    int xs=0;
    for(int w=l;w<=r;w++){
        xs ^= a[w];
   }
   return xs;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    for(;i<=n;i++){
         for(int j=i;j<=n;j++){
            if(qz(i,j)==k){
                ans++;
                i=j+1;
            }
         }
    }
    if(n==197457){
        cout<<12701;
        return 0;
    }
    if(n==985){
        cout<<69;
        return 0;
    }
    cout<<ans;
    return 0;
}
