#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct o{
    int a,b,c;
} x[100005];
void dfs1(int a,int b,int s,int sum) {
    if (a==n/2) {
        for (int i=s;i<=n;i++) {
            sum+=x[i].b;
        }
        ans=max(ans,sum);
        return;
    }
    if (b==n/2) {
        for (int i=s;i<=n;i++) {
            sum+=x[i].a;
        }
        ans=max(ans,sum);
        return ;
    }
    dfs1(a+1,b,s+1,sum+x[s].a);
    dfs1(a,b+1,s+1,sum+x[s].b);
}
void dfs3(int b,int c,int s,int sum) {
    if (b==n/2) {
        for (int i=s;i<=n;i++) {
            sum+=x[i].c;
        }
        ans=max(ans,sum);
        return;
    }
    if (c==n/2) {
        for (int i=s;i<=n;i++) {
            sum+=x[i].b;
        }
        ans=max(ans,sum);
        return ;
    }
    dfs3(b+1,c,s+1,sum+x[s].b);
    dfs3(b,c+1,s+1,sum+x[s].c);
}
void dfs4(int a,int c,int s,int sum) {
    if (a==n/2) {
        for (int i=s;i<=n;i++) {
            sum+=x[i].c;
        }
        ans=max(ans,sum);
        return;
    }
    if (c==n/2) {
        for (int i=s;i<=n;i++) {
            sum+=x[i].a;
        }
        ans=max(ans,sum);
        return ;
    }
    dfs4(a+1,c,s+1,sum+x[s].a);
    dfs4(a,c+1,s+1,sum+x[s].c);
}
void dfs2(int a,int b,int c,int s,int sum) {
    if (a==n/2) {
        dfs3(b,c,s,sum);
        return;
    }
    if (b==n/2) {
        dfs4(a,c,s,sum);
        return;
    }
    if (c==n/2) {
        dfs1(a,b,s,sum);
        return;
    }
    dfs2(a+1,b,c,s+1,sum+x[s].a);
    dfs2(a,b+1,c,s+1,sum+x[s].b);
    dfs2(a,b,c+1,s+1,sum+x[s].c);
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        int f=1;
        for (int i=1;i<=n;i++) {
            scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
            if (x[i].c!=0) {
                f=0;
            }
        }
        if (f) {
            dfs1(0,0,1,0);
        }else {
            dfs2(0,0,0,1,0);
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
