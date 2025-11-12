#include<bits/stdc++.h>
using namespace std;
int n,a[5010],x[5010],s,f,ans;
bool check(int d){
    s=0;f=0;
    for(int i=1;i<=d;i++){
        s+=x[i];
        f=max(x[i],f);
    }
    if(s>f) return true;
    else return false;
}
void dfs(int dep,int cnt){
    if(cnt==n) return;
    for(int i=1;i<=n;i++)
        x[i]=0;
    for(int i=1;i<=n;i++){
        x[i]=a[i];
        dfs(dep+1,cnt+1);
        if(check(cnt))
            ans++;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,3);
    cout<<ans;
    return 0;
}
