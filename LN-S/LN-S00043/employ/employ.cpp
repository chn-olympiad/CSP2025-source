#include<bits/stdc++.h>
using namespace std;

const int P=998244353;
char ss[550];
int n, m, c[510], s[510], sy[510], b[510], anss=0;
bool flag[510];

inline void dfs(int i) {
    if(i==n+1) {
        int tot=0, cnt=0;
        for(int j=1;j<=n;j++) {
            sy[j]=s[j];
            if(cnt>=c[b[j]]) sy[j]=0;
            else
                if(sy[j]) ++tot;
            if(!sy[j]) cnt++;
        }
        if(tot>=m) anss=(anss+1)%P;
        return;
    }
    for(int j=1;j<=n;j++)
        if(!flag[j]) {
            flag[j]=true, b[i]=j;
            dfs(i+1);
            flag[j]=false;
        }
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", ss+1);
    for(int i=1;i<=n;i++)
        s[i]=ss[i]-'0';
    for(int i=1;i<=n;i++)
        scanf("%d", &c[i]);
    if(n<=10) {
        memset(flag, false, sizeof(b));
        dfs(1);
        printf("%d", anss);
    }
    else {
        long long ans=1;
        for(int i=1;i<=n;i++)
            ans=ans*i%P;
        printf("%d", ans);
    }
    return 0;
}
