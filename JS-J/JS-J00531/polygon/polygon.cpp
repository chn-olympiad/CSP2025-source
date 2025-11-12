#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;
const int mod = 998244353;
int n;
int a[MAXN];
long long cnt = 0;

void dfs(int nm,int xs){
    if (a[xs] * 2 < nm) cnt++;
    for (int i = xs+1;i < n;i++)
        dfs(nm + a[i],i);
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i = 0;i < n;i++)   scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i = 0;i < n;i++){
        dfs(a[i],i);
        cnt = cnt % mod;
    }
    printf("%d",cnt % mod);
    return 0;
}
