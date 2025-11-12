#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt;
int a[5001];
void dfs(int x,int maxsum,int sum,int i,int xsum){
    if (xsum == i){
        if (maxsum*2 < sum) cnt++;
        cnt %= 998244353;
        return;
    }
    if (x > n) return;
    if (x+i-xsum > n) return;
    dfs(x+1,max(maxsum,a[x]),sum+a[x],i,xsum+1);
    dfs(x+1,maxsum,sum,i,xsum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 3;i <= n;i++){
        dfs(1,0,0,i,0);
    }
    cout << cnt;
    return 0;
}
