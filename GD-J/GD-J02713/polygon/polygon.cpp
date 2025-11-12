#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10005];
int n;
int b[10005];
bool vis[10005];
long long cnt;
void dfs(int step){

    if(step>3){
        long long num = 0,maxn = -1;
        for(int i = 1;i<=step-1;i++){
            num+=b[i];
            if(b[i]>maxn){
                maxn = b[i];
            }
        }
        if(num>2*maxn){
            cnt++;
            cnt%=998244353;

        }
    }
    if(step>n){
        return;
    }
    for(int i = step;i<=n;i++){
        if(vis[i] == 1||a[i]<b[step-1]) continue;
        else{
            b[step] = a[i];
            vis[i] = 1;
            dfs(step+1);
            vis[i] = 0;
        }
    }

}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1);

    cout<<cnt;

    return 0;
}
