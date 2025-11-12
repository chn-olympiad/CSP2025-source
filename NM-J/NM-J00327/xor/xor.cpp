#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int used1[500010],used[500010];
int ans0,ans1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            ans0++;
        }
        else if(a[i]==1&&a[i-1]==1&&used[i-1]==0){
            ans0++;
            used[i-1]=1;
            used[i]=1;
        }
        if(a[i]==1){
            ans1++;
        }
    }
    if(k==0){
        cout<<ans0;
    }
    else if(k==1){
        cout<<ans1;
    }
    else{
        cout<<n/2;
    }
    return 0;
}
