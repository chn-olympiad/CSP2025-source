#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
long long f[5005];
long long ans;
void dfs(int step,long long sum,int g){
    if(step>=n){
        return;
    }
    if(g>=2){
        if(sum>a[step]){
            if(ans<=998244352){
                ans++;
            }
            else
                ans=0;
        }
    }
    dfs(step+1,sum+a[step],g+1);
    dfs(step+1,sum,g);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
