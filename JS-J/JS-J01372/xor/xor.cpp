#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[5005][5005],b[5005];
void dfs(int root,int cnt){
    if(root>=n){
        if(ans<cnt)ans=cnt;
        return;
    }
for(int i=0;i<n-root;i++){
    if(a[root][i]==k){
    //cout<<root<<" "<<i<<" "<<cnt<<"\n";
    dfs(root+i+1,cnt+1);
    }else{
    //cout<<root<<" "<<i<<" "<<cnt<<"\n";
    dfs(root+i+1,cnt);
    }
    }
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    if(n>1000){
        cout<<0;
        return 0;
    }
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>b[i];
        a[i][0]=b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            a[i][j]=a[i][j-1]^b[i+j];
        }
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
