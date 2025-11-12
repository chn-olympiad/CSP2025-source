#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5002];
//int b[5002];
bool dfs(int startx,int dep,int sum,int maxx){
    if(dep==0){
        if(sum>maxx*2){
            return true;
        }
        return false;
    }
    for(int i=startx+1;i<=n-dep+startx;i++){
//       dfs(i,dep-1,sum+b[startx]-b[startx-1],max(maxx,b[startx]-b[startx-1]));
        dfs(i,dep-1,sum+a[i],max(maxx,a[i]));
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
//        b[i]=b[i-1]+a[i];
    }
    int j=3;
    while(j<=n){
        for(int i=1;i<=n-j;i++){
            if(dfs(i,j-1,a[i],0)==true){
                ans++;
            }
        }
        j++;
    }
    cout<<ans%998244353;
    return 0;
}
