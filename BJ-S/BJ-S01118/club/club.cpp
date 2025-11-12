#include<bits/stdc++.h>
using namespace std;
int t,a,b[100005],c[100005],d[100005],ge[5],cnt,fl[100005],ans;
struct m{
    int cha,id;
}e[200005];
bool cmp(m a,m b){
    return a.cha<b.cha;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        ge[1]=0;
        ge[2]=0;
        ge[3]=0;
        scanf("%d",&a);
        for(int i=1;i<=a;i++){
            scanf("%d %d %d",&b[i],&c[i],&d[i]);
            fl[i]=0;
            int mx=max(max(b[i],c[i]),d[i]);
            ans+=mx;
            if(mx==b[i])ge[1]++;
            else if(mx==c[i])ge[2]++;
            else ge[3]++;
        }
        int p=a/2;
        if(ge[1]>p){
            cnt=0;
            for(int i=1;i<=a;i++){
                if(max(max(b[i],c[i]),d[i])==b[i]){
                    e[++cnt].cha=b[i]-c[i];
                    e[cnt].id=i;
                    e[++cnt].cha=b[i]-d[i];
                    e[cnt].id=i;
                }
            }
            sort(e+1,e+cnt+1,cmp);
            for(int i=1;i<=cnt;i++){
                if(fl[e[i].id]==0){
                    ge[1]--;
                    if(b[i]-e[i].cha==c[i])ge[2]++;
                    else ge[3]++;
                    b[i]=-1e9;
                    fl[e[i].id]=1;
                    ans-=e[i].cha;
                    if(ge[1]==p)break;

                }
            }
        }
        if(ge[2]>p){
            cnt=0;
            for(int i=1;i<=a;i++){
                if(max(max(b[i],c[i]),d[i])==c[i]){
                    e[++cnt].cha=c[i]-b[i];
                    e[cnt].id=i;
                    e[++cnt].cha=c[i]-d[i];
                    e[cnt].id=i;
                }
                fl[i]=0;
            }
            sort(e+1,e+cnt+1,cmp);
            for(int i=1;i<=cnt;i++){
                if(fl[e[i].id]==0){
                    ge[2]--;
                    if(c[i]-e[i].cha==b[i])ge[1]++;
                    else ge[3]++;
                    c[i]=-1e9;
                    fl[e[i].id]=1;
                    ans-=e[i].cha;
                    if(ge[2]==p)break;

                }
            }
        }
        if(ge[3]>p){
            cnt=0;
            for(int i=1;i<=a;i++){
                if(max(max(b[i],c[i]),d[i])==d[i]){
                    e[++cnt].cha=d[i]-b[i];
                    e[cnt].id=i;
                    e[++cnt].cha=d[i]-c[i];
                    e[cnt].id=i;
                }
                fl[i]=0;
            }
            sort(e+1,e+cnt+1,cmp);
            for(int i=1;i<=cnt;i++){
                if(fl[e[i].id]==0){
                    ge[3]--;
                    if(d[i]-e[i].cha==b[i])ge[1]++;
                    else ge[2]++;
                    d[i]=-1e9;
                    fl[e[i].id]=1;
                    ans-=e[i].cha;
                    if(ge[3]==p)break;

                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
