#include<bits/stdc++.h>
using namespace std;
int n,m,cn[501],ans[501];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int hard,cnt[501]={0};
    cin>>hard;
    for(int i=n;i>0;i--){
        cnt[n-i+1]=hard%(10^n);
    }
    for(int i=1;i<=n;i++) cin>>cn[i];
    for(int i=1;i<=n;i++){
        if(cnt[i]){
            ans[i]=cnt[i-1];
        }else{
            ans[i]=cnt[i-1]+1;
        }
    }
    if(ans[n]==0){
        int an=1;
        for(int i=1;i<=n;i++) an=an*i%998244353;
    }else{
        int an=1;
        for(int i=1;i<=n-ans[n];i++) an=an*i%998244353;
    }
    return 0;
}
