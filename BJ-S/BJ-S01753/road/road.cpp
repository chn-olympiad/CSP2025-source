/*
 ____
/    \  This is a sugar bean.
\____/  Sugar bean don't judge your flaws.
May the God of Sugar Bean bless all OIers!
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define M 1100005
#define N 10015
LL read(){
    char ch=getchar();
    int p=1;
    LL x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')p=-p;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*p;
}
void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
LL fa[N],c[25];
struct node{
    LL u,v,w;
    LL buy;
}edge[M];
bool cmp(node a,node b){
    return a.w<b.w;
}
LL findf(LL x){
    return (fa[x]==x?x:fa[x]=findf(fa[x]));
}
void unionn(LL x,LL y){
    fa[findf(x)]=y;
}
bool judge(LL x,LL y){
    return findf(x)==findf(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    LL n,m,k,x,y,z,edgecnt=0,ans=LLONG_MAX;
    bool subA=1;
    n=read(),m=read(),k=read();
    for(LL i=1;i<=m;i++){
        x=read(),y=read(),z=read();
        edge[++edgecnt]={x,y,z,0};
    }
    for(LL i=1;i<=k;i++){
        c[i]=read();
        if(c[i])subA=0;
        for(LL j=1;j<=n;j++){
            y=read();
            edge[++edgecnt]={i+n,j,y,i};
        }
    }
    sort(edge+1,edge+edgecnt+1,cmp);
    for(LL vis=(subA?(1<<k)-1:0);vis<=(1<<k)-1;vis++){
        LL now=0,cnt=0,temp=0;
        for(LL i=0;i<k;i++){
            //printf("%lld\n",vis>>i);
            if((vis>>i)&1){
                temp++;
                now+=c[i+1];
                //printf("+%lld\n",c[i+1]);
            }
        }
        for(LL i=1;i<=n+k;i++)fa[i]=i;
        for(LL i=1;i<=edgecnt;i++){
            if((!subA)&&edge[i].buy&&(!((vis>>edge[i].buy-1)&1)))continue;
            if(!judge(edge[i].u,edge[i].v)){
                unionn(edge[i].u,edge[i].v);
                //printf("%lld %lld %lld\n",edge[i].u,edge[i].v,edge[i].w);
                now+=edge[i].w;
                cnt++;
            }
            if(cnt>=n-1+temp)break;
        }
        //printf("vis:%lld now:%lld\n",vis,now);
        ans=min(ans,now);
    }
    write(ans);
    return 0;
}
