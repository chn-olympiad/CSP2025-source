#include<bits/stdc++.h>

using namespace std;

int n;
int a[5001];
bool b[5001];
int ans = 0;
int s = 0;
long long sum = 0;
int m = 0;

inline void dfs(int i){
    if(i == n + 1){
        m = 0,sum = 0,s = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] == true){
                s++;
                sum += a[i];
                m = max(m,a[i]);
            }
        }
        if(s >= 3 && sum > 2 * m)
            ans++;
        return;
    }
    b[i] = true;
    dfs(i + 1);
    b[i] = false;
    dfs(i + 1);
    return;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n; i++){
        scanf("%d",&a[i]);
    }
    memset(b,false,sizeof(b));
    dfs(1);
    printf("%d\n",bu,ans % 998244353);
    return 0;
}
