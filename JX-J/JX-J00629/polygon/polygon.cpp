#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5005],s[5005];
int ans;
int c(int x,int y){
    int s=1;
    if(y>x-y) y=x-y;
    for(int i=x-y+1;i<=x;i++) s*=i;
    return s/y;
}
void dfs(int x,int q,int sum){
    if(q==k){
        int t=upper_bound(a+1,a+1+n,sum)-a-1;
        if(a[t-1]==sum) t-=2;
        else t--;
        ans+=t-q;
        ans%=998244353;
    }
    for(int i=x+1;i<=n;i++)
        dfs(i,q+1,sum+a[i]);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    bool t=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) t=0;
    }
    if(t){
        int s=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1) s++;
        for(int i=3;i<=s;i++){
            ans+=c(s,i);
            ans/=998244353;
        }
        cout<<ans;
        return 0;
    }
    sort(a,a+n);
    for(k=2;k<n;k++){
        dfs(0,0,0);
    }
    cout<<ans;
    return 0;
 }
