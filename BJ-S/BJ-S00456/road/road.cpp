#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=1000005;

int n,m,k;
long long ans;
int cnt=0;

int fath[N+10],flagcnt=0;
int flag1=1;

struct bian{
    int u,v,w;
}e[2*M];

bool cmp(bian a,bian b){
    return a.w<b.w;
}

int fd(int x){
    if(fath[x]!=x) fath[x]=fd(fath[x]);
    return fath[x];
}

void bd(){
    int biancnt=0;
    while(flagcnt<(n+k-1)){
        biancnt++;
        int left=fd(e[biancnt].u);
        int right=fd(e[biancnt].v);
        if(left == right){
            continue;
        }
        flagcnt++;
        ans+=e[biancnt].w;
        fath[left]=right;
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        cnt++;
        scanf("%d%d%d",&e[cnt].u,&e[cnt].v,&e[cnt].w);
    }
    for(int i=1;i<=k;i++){
        int c;
        scanf("%d",&c);
        if(c!=0) flag1=0;
        for(int j=1;j<=n;j++){
            cnt++;
            e[cnt].u=n+i;
            e[cnt].v=j;
            scanf("%d",&e[cnt].w);
        }
    }
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=n+k;i++){
        fath[i]=i;
    }
    bd();
    printf("%d",ans);
    return 0;
}
