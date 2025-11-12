#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5005],ans=0;
void dfs(long long x,long long maxn,long long y){
    if(x>n){
        if(y>maxn*2){
            ans++;

        }
    return ;
    }
    if(a[x]>maxn) {
        dfs(x+1,a[x],y+a[x]);
        dfs(x+1,maxn,y);
    }else{
        dfs(x+1,maxn,y+a[x]);
        dfs(x+1,maxn,y);
    }

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
