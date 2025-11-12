#include<bits/stdc++.h>
const int N=1e5;
int n,a[N+5][3],t[N+5],p[N+5],sa[N+5],o[3];
int nw;
long long ans;
int id[N+5];
bool cmp(int x,int y){return a[nw][x]>a[nw][y];}
bool cmp2(int x,int y){return sa[x]<sa[y];}
void clean(){
    ans=0;
    for(int i=0;i<=2;++i)t[i]=0;
}
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        nw=i;
        for(int j=0;j<=2;++j)scanf("%d",&a[i][j]),o[j]=j;
        std::sort(o,o+3,cmp);
        p[i]=o[0],sa[i]=a[i][o[0]]-a[i][o[1]];
        ans+=a[i][o[0]];
        ++t[p[i]];
        id[i]=i;
    }
    std::sort(id+1,id+n+1,cmp2);
    for(int i=0;i<=2;++i)if(t[i]>n/2){
        //printf("A");
        for(int j=1;j<=n;++j)if(p[id[j]]==i){
            ans-=sa[id[j]];
            --t[i];
            if(t[i]<=n/2)break;
        }
        break;
    }
    printf("%lld\n",ans);
}
int T;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        clean();
        work();
    }
    return 0;
}