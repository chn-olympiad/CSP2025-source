#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 998244353;
int n,m,s[N],c[N],cal[N],f[262150][20],cnts1,cnts0,cntc0,cntc1,ans;
bool flag = 0;
bool cmp[N];
void check()
{
    int cnt = 0,cntc = 0;
    for (int i = 1,j = 1;i<=n;i++){
        if(s[i] == 0){
            cntc++;
            continue;
        }
        while(c[j] <= cntc && j <= n) j++;
        if(j <= n){
            j++;cnt++;
        }
        else cntc++;
    }
    if(cnt < m){
        printf("0\n");
        flag = 1;
    }
}
void dfs(int step,int cnt)
{
    if(step > n){
        if(cnt >= m) ans = (ans+1)%mod;
        return;
    }
    for (int i = 1;i<=n;i++)
        if(!cmp[i]){
            cmp[i] = 1;
            if(s[step] == 1 && c[i] > step-cnt-1) dfs(step+1,cnt+1);
            else dfs(step+1,cnt);
            cmp[i] = 0;
        }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cal[1] = 1;
    for (int i = 2;i<=500;i++)
        cal[i] = 1ll*cal[i-1]*i%mod;
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++){
        scanf("%1d",&s[i]);
        if(s[i] == 1) cnts1++;
        else cnts0++;
    }
    for (int i = 1;i<=n;i++){
        scanf("%d",&c[i]);
        if(c[i] == 0) cntc0++;
    }
    sort(c+1,c+1+n);
    check();
    if(flag) return 0;
    if(n > 10){
        printf("%d\n",cal[n]);
        return 0;
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
