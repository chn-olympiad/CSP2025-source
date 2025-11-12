#include <bits/stdc++.h>
#define long long
using namespace std;
//polygon

const int MOD = 998244353;
int n,a[5007],cnt,nxt[5007],pow2[5007];

void dfs(int pos,int sum,int num){
    if (pos > n){
        return;
    }
    dfs(pos + 1,sum,num);
    if (num >= 2 && sum > a[pos]){
        //printf("%d %d %d\n",pos,sum + a[pos],a[pos]);
        cnt = (cnt + pow2[nxt[pos] - pos - 1]) % MOD;
        for (int i = 1;i <= nxt[pos] - pos;i++)
            dfs(nxt[pos],sum + a[pos] * i,min(3,num + i));
    }
    else dfs(pos + 1,sum + a[pos],min(3,num + 1));
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    pow2[0] = 1;
    for (int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    sort(a + 1,a + 1 + n);
    nxt[n] = n + 1;
    for (int i = n - 1;i >= 1;i--){
        if (a[i + 1] != a[i])nxt[i] = i + 1;
        else nxt[i] = nxt[i + 1];
    }
    dfs(1,0,0);
    printf("%d\n",cnt);
    return 0;
}
