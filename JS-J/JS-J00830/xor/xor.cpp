#include<bits/stdc++.h>
using namespace std;
int a[500005],vis[500005],f[1005][1005];
bool check(int a,int b){
    int ff=0;
    for(int i=a;i<=b;i++){
        if(vis[i]) ff=1;
    }
    if(!ff) return true;
    else return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i][i]=a[i];
        for(int j=i;j<=n;j++) f[i][j]=a[j]^f[i][j-1];
    }
    int ans=0;
    for(int l=0;l<n;l++){
        for(int i=1;i+l<=n;i++){
            int j=i+l;
            if(f[i][j]==k&&check(i,j)){
                for(int k=i;k<=j;k++) vis[k]=1;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
