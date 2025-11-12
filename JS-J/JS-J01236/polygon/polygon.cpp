#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 998244353
int n,a[5010],cnt  = 0;
void dfs(int x,int sum ,int maxx,int deep){
    if(deep == 1){
        if(sum>maxx*2)cnt = (cnt+1)%M;
        return ;
    }
    for(int i = x+1;i<=n;i++){
        dfs(i,sum+a[i],max(maxx,a[i]),deep-1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int x = 0;
    for(int i = 1;i<=n;i++){
            cin >> a[i];
            x = max(a[i],x);
    }
    if(x == 1){
        int ans = 1;
        for(int i = 1;i<=n;i++){
            ans = ans*2%M;
        }
        cout << abs((ans-1-n-(n*(n-1)/2)%M)%M);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i = 3;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dfs(j,a[j],a[j],i);
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
