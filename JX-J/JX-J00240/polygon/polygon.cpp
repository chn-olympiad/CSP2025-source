#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010];
long long l;
void dfs(int cnt,int dep,long long sum){
    if(dep==n+1){
        if(cnt>=3){
            if(sum>b[cnt-1]*2) l++;
        }
        return;
    }
    b[cnt]=a[dep];
    dfs(cnt+1,dep+1,sum+b[cnt]);
    dfs(cnt,dep+1,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,1,0);
    l%=998244353;
    cout<<l;
    return 0;
}
