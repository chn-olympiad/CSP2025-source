#include<bits/stdc++.h>
using namespace std;
const int mol=998244353;
int n;
int a[5005];
bool b[5005];
int ans;
void dfs(int x,long long cnt,int mx,int v){
    if(x>n){
        return;
    }
    if(cnt>mx*2&&v==0){
        ans=(ans+1)%mol;
    }
    dfs(x+1,cnt+a[x],a[x],0);
    dfs(x+1,cnt,mx,1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(0,0ll,0,1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
