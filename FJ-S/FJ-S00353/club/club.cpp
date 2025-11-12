#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n;
long long ans;
int a[maxn][4];
int cnt[4];
int c[maxn];
struct node{
    int id,tx,ch;
}dt[maxn];
bool cmp(node x,node y){
    return x.tx<y.tx;
}
void work(int d){
    int res=0;
    for(int i=1;i<=n;i++){
        if(c[i]!=d) continue;
        dt[++res].id=i;
        if(d==1){
            if(a[i][2]>=a[i][3]) dt[res].ch=2,dt[res].tx=a[i][1]-a[i][2];
            else dt[res].ch=3,dt[res].tx=a[i][1]-a[i][3];
        }else if(d==2){
            if(a[i][1]>=a[i][3]) dt[res].ch=1,dt[res].tx=a[i][2]-a[i][1];
            else dt[res].ch=3,dt[res].tx=a[i][2]-a[i][3];
        }else{
            if(a[i][1]>=a[i][2]) dt[res].ch=1,dt[res].tx=a[i][3]-a[i][1];
            else dt[res].ch=2,dt[res].tx=a[i][3]-a[i][2];
        }
    }    
    sort(dt+1,dt+res+1,cmp);
    for(int i=1;i<=res-(n/2);i++)c[dt[i].id]=dt[i].ch;
}
int main(){
    freopen("club.in","r",stdin); 
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        cnt[1]=cnt[2]=0;
        cnt[3]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) c[i]=1,cnt[1]++;
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) c[i]=2,cnt[2]++;
            else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]) c[i]=3,cnt[3]++;
        }
        //cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<"\n";
        if(cnt[1]>(n/2)) work(1);
        else if(cnt[2]>(n/2)) work(2);
        else if(cnt[3]>(n/2)) work(3);
        for(int i=1;i<=n;i++) ans+=1ll*a[i][c[i]];
        printf("%lld\n",ans);
    }
    return 0;
}