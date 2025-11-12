#include<bits/stdc++.h>
#define lol long long
using namespace std;
lol n,ans=0;
lol a[5005];
bool dfs(int i,lol summ,lol maxx,lol tott){
    if(i==n+1){
        if(tott<3)return 0;
        if(summ>maxx*2){
            ans++;
            return 1;
        }
        return 0;
    }
    int op=dfs(i+1,summ+a[i],max(maxx,a[i]),tott+1);
    int po=dfs(i+1,summ,maxx,tott);
    if(op==1||po==1)return 1;
    else return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1,0ll,0ll,0ll);
        cout<<ans;
    return 0;
    }


