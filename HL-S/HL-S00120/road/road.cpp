#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=1e6+10;
int n,m,t;
int x,y,z;
int c;
int fa[N];
long long ans=0;
struct node {
    int a,b,c;
} a[M << 1];
int k=0;
bool cmp(node x,node y) {
    return x.c<y.c;
}
int findfa(int x) {
    if(fa[x]==x) return x;
    else return fa[x]=findfa(fa[x]);
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&x,&y,&z);
        k++;
        a[k].a=x;
        a[k].b=y;
        a[k].c=z;
    }
    for(int i=1;i<=t;i++) {
        scanf("%d",&c);
        for(int j=1;j<=n;j++) {
            scanf("%d",&x);
            k++;
            a[k].a=n+i;
            a[k].b=j;
            a[k].c=x;
        }
    }
    sort(a+1,a+k+1,cmp);
    n+=t;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        fa[i]=i;
    }
    for(int i=1;i<=k;i++) {
        int s=a[i].a,e=a[i].b,len=a[i].c;
        int fx=findfa(s),fy=findfa(e);
        if(fx!=fy) {
            fa[fx]=fy;
            cnt++;
            ans+=len;
        }
        if(cnt==n-1) break;
    }
    printf("%lld",ans);
    return 0;
}
