#include <bits/stdc++.h>
using namespace std;

int n, t, ans;
int a[5005];
int c[5005];
bool f[5005];

bool isOK(int x){
    int sum=0, mx=0;
    for(int i=1; i<=x; i++){
        sum+=c[i];
        mx=max(mx, c[i]);
    }
    if(sum>2*mx) return true;
    else return false;
}

void dfs(int x, int k){
    if(x==0){
        if(isOK(t)) ans=(ans+1)%998244353;
        return ;
    }

    for(int i=k+1; i<=n; i++){
        if(!f[i]){
            t++;
            c[t]=a[i];
            f[i]=1;
            dfs(x-1, i);
            f[i]=0;
            t--;
        }
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=3; i<=n; i++)
        dfs(i,0);

    cout<<ans<<endl;

    return 0;
}
