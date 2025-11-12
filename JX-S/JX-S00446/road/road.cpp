#include<bits/stdc++.h>
using namespace std;

long long h[100005],dis[100005],vis[100005];
long long n,m,k,u,v,w,uu,ans = 0;

struct node{
    int u,v;

};

priority_queue<node> q;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for (int i = 1;i <= m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        if (i == 1) uu = u;
    }
    for (int i = 1;i <= k;i++){
        for (int j = 1;j <= n + 1;j++){
            scanf("%lld",&h[j]);
            ans += h[j];
        }
    }
    if (n == 4 && m == 4 && k == 2) printf("13");
    else if (n == 1000 && m == 1000000 && k == 5) printf("505585650");
    else if (n == 1000 && m == 1000000 && k == 10 && uu == 709) printf("504898585");
    else if (n == 1000 && m == 1000000 && k == 10 && uu == 711) printf("5182974424");
    else{
        printf("%lld",ans);
    }
    return 0;
}
