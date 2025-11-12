#include<bits/stdc++.h>

using namespace std;
long long cnt = 0;
long long n;
long long a[5050];
void dfs(long long now,long long bs,long long mx, long long h){
    if(now > n){
        if(bs >= 3 && h > (mx * 2)){
            cnt++;
            cnt %= 998244353;
        }
        return;
    }
    dfs(now + 1,bs + 1,max(mx,a[now]),h + a[now]);
    dfs(now + 1,bs + 1,max(mx,a[now]),h + a[now]);
    dfs(now + 1,bs,mx,h);

    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i = 1;i <= n ;i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    dfs(1,1,a[1],0);
    cout<<cnt;
    return 0;
}
