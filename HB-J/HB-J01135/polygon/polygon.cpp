#include "bits/stdc++.h"
using namespace std;
int n,ans;
int arr[5005]={};
int book[5005]={};

void dfs(int sum,int idx,int m){
    //cout<<arr[idx]<<" ";
    if(idx==0) return;

     if(idx>=1){
        if(sum-arr[idx]<0 and m>=2) ans++;
        dfs(sum-arr[idx],idx-1,m+1);
        dfs(sum,idx-1,m);
     }
 }

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    stable_sort(arr+1,arr+n+1);
    for(int i=n;i>=1;i--){
        int pro=arr[i];
        dfs(pro,i-1,1);
    }
    cout<<ans;
    return 0;
}
