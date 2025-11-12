#include<bits/stdc++.h>
using namespace std;
int a[500001],n,k,ser,c,v[500001];
void dfs(int x,int l){
    if(x>=n){
        return;
    }
    if(l==k && x!=0){
        ser++;
    }
    for(int i=0;i<n;i++){
        if(v[i]==0){
            v[i]=1;
            dfs(x+1,l^a[i]);
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    dfs(0,0);
    if(a[0]==k){
        ser++;
    }
    cout<<ser;
    return 0;
}
