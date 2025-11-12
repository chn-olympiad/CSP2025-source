#include<bits/stdc++.h>
using namespace std;
const int N=50000005;
int n,k,a[N],vis[N],ans;
int la,lb;
int x(int a1,int b1){
    int h=0;
    for(int i=a1;i<=b1;i++){
        h=(h^a[i]);
        if(h==k){
            la=a1,lb=k;
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    if(k==0){
        cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j]==k&&vis[j]==0){
                ans++;
                vis[j]=1;
                continue;
            }
            if(vis[i]||vis[j]){
                continue;
            }
            if(x(i,j)==1){
                    ans++;
                for(int l=la;l<=lb;l++){
                    vis[l]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
