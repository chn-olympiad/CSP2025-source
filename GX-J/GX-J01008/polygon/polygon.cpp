#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[5005],cnt=0;
bool flag[5005];
void dfs(int g,int i,int now){
    if(now>=g){
        int z=0,maxx=-1;
        for(int k=1;k<=n;k++){
            if(flag[k]){
                z=z+a[k];
                maxx=max(maxx,a[k]);
            }
        }

        if(z>maxx*2){
            cnt++;
            cnt%=998244353;
        }
        return;
    }
    if(i>n)return;
    flag[i]=true;
    dfs(g,i+1,now+1);
    flag[i]=false;
    dfs(g,i+1,now);

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=3;i<=n;i++){
        dfs(i,1,0);
    }
    cout<<cnt;
    return 0;
}
