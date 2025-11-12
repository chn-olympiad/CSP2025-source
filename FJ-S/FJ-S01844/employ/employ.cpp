#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
using namespace std;

const int N=20,mod=998244353;
int n,m,f[1<<18][N],c[N];
char s[N];

void add(int &x,int y){if((x+=y)>=mod)x-=mod;}


signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=0;i<n;i++)scanf("%d",&c[i]);
    f[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        int a=__builtin_popcount(i);
        for(int j=0;j<=a;j++)if(f[i][j])
            for(int k=0;k<n;k++)
                if(i>>k&1^1)add(f[i|1<<k][j+(s[a]=='0'||j>=c[k])],f[i][j]);
    }
    int ans=0;
    for(int i=0;i<=n-m;i++)add(ans,f[(1<<n)-1][i]);
    printf("%d\n",ans);
    return 0;
}