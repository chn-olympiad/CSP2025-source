#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int ans=0;
int dfs(int x,int xmx,int cnt,int numb){
    int mx=xmx;
    for(int i=x;i<min(a.size(),a.size()-3+numb);i++){
        mx=max(mx,a[i]);
        cnt+=a[i];
        if(cnt>mx*2 && numb>2){
            ans++;ans%=998244353;
        }
        if(i+1<a.size())dfs(i+1,mx,cnt,numb+1);
        cnt-=a[i];
        mx=xmx;
    }
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    a.resize(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(0,0,0,1);
    cout<<ans;
    return 0;
}