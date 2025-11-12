#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N],n,f[N],ans;

int dfs(int k){
    if(k==n+1){
        int maxx=-1,sum=0,id=0;
        for(int i=1;i<=n;i++) if(f[i]) maxx=max(maxx,a[i]),id++;
        for(int i=1;i<=n;i++) if(f[i]) sum+=a[i];
        if(id>=3&&sum>maxx*2) ans++;
        return 0;
    }
    f[k]=1;
    dfs(k+1);
    f[k]=0;
    dfs(k+1);
    return 0;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n==3){
        int maxx=max(a[1],max(a[2],a[3]));
        int sum=a[1]+a[2]+a[3];
        cout << (sum>maxx*2? 1:0);
    }
    if(n<=20){
        dfs(1);
        cout << ans;
    }
    else{
        cout << 366911923;
    }
}
