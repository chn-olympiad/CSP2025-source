#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,ans;
struct node{
    int a,b,c;
}h[N];
bool f[N];
bool aa(node x,node y){
    return x.a>y.a;
}
bool bb(node x,node y){
    return x.b>y.b;
}
bool cc(node x,node y){
    return x.c>y.c;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(f,false,sizeof(f));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&h[i].a,&h[i].b,&h[i].c);
        }

        int ansa=0;
        sort(h+1,h+n+1,aa);
        for(int i=1;i<=n/2;i++){
            ansa+=h[i].a;
        }
        for(int i=n/2+1;i<=n;i++){
            ansa+=max(h[i].c,h[i].b);
        }

        int ansb=0;
        sort(h+1,h+n+1,bb);
        for(int i=1;i<=n/2;i++){
            ansb+=h[i].b;
        }
        for(int i=n/2+1;i<=n;i++){
            ansb+=max(h[i].c,h[i].a);
        }

        int ansc=0;
        sort(h+1,h+n+1,cc);
        for(int i=1;i<=n/2;i++){
            ansc+=h[i].c;
        }
        for(int i=n/2+1;i<=n;i++){
            ansc+=max(h[i].b,h[i].a);
        }

        ans=max(max(ansa,ansb),ansc);
        printf("%d\n",ans);
    }
    return 0;
}