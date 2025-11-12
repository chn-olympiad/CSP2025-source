#include<bits/stdc++.h>
using namespace std;
const int inf=5e3+10,mod=998244353;
int n,a[inf];
bool fl;
int dfs(int st,int mn,int last){
    if(st>n){
        return 0;
    }
    int cnt=0;
    for(int i=last+1;i<=n;i++){
        if(a[i]<mn){
            cnt++;
        }
        cnt+=dfs(st+1,mn+a[i],i);
        cnt%=mod;
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<dfs(1,0,0);
    return 0;
}
