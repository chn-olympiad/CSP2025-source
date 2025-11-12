#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n,k;
int a[N];
int vis[N];
int now;
int ans;
int en;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    vis[0] = 0;
    for(int i = 1;i <= N - 10;i++) vis[i] = -1;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        now ^= a[i];
        if(vis[now ^ k] >= en){
            en = i;
            ans++;
            now = 0;
        }
        vis[now] = i;
    }
    cout<<ans;
}
