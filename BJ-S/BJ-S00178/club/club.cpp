#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int val,id;
}e[100005],f[100005];
int t,n,m,a[100005][5],x[100005],y[100005],u[100005],v[100005],w[100005],ord[100005][5];
int cnt[5],d,pos[100005],ans,ext[100005],tot,maxsz,maxps;
bool cmp(node n1,node n2){
    return n1.val<n2.val;
}
void update(){
    if(cnt[1]>=cnt[2]&&cnt[2]>=cnt[3])maxps=1;
    else if(cnt[1]>=cnt[3]&&cnt[3]>=cnt[2])maxps=1;
    else if(cnt[2]>=cnt[1]&&cnt[1]>=cnt[3])maxps=2;
    else if(cnt[2]>=cnt[3]&&cnt[3]>=cnt[1])maxps=2;
    else if(cnt[3]>=cnt[1]&&cnt[1]>=cnt[2])maxps=3;
    else if(cnt[3]>=cnt[2]&&cnt[2]>=cnt[1])maxps=3;
    maxsz=cnt[maxps];
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=cnt[4]=0;
        ans=0;
        tot=0;
        maxsz=0;
        memset(ext,0,sizeof(ext));
        memset(pos,0,sizeof(pos));
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        memset(ord,0,sizeof(ord));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]){
                u[i]=a[i][1];
                v[i]=a[i][2];
                w[i]=a[i][3];
                ord[i][1]=1;
                ord[i][2]=2;
                ord[i][3]=3;
                pos[i]=1;
            }
            else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]){
                u[i]=a[i][1];
                v[i]=a[i][3];
                w[i]=a[i][2];
                ord[i][1]=1;
                ord[i][2]=3;
                ord[i][3]=2;
                pos[i]=1;
            }
            else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]){
                u[i]=a[i][2];
                v[i]=a[i][1];
                w[i]=a[i][3];
                ord[i][1]=2;
                ord[i][2]=1;
                ord[i][3]=3;
                pos[i]=2;
            }
            else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]){
                u[i]=a[i][2];
                v[i]=a[i][3];
                w[i]=a[i][1];
                ord[i][1]=2;
                ord[i][2]=3;
                ord[i][3]=1;
                pos[i]=2;
            }
            else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]){
                u[i]=a[i][3];
                v[i]=a[i][1];
                w[i]=a[i][2];
                ord[i][1]=3;
                ord[i][2]=1;
                ord[i][3]=2;
                pos[i]=3;
            }
            else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]){
                u[i]=a[i][3];
                v[i]=a[i][2];
                w[i]=a[i][1];
                ord[i][1]=3;
                ord[i][2]=2;
                ord[i][3]=1;
                pos[i]=3;
            }
            x[i]=u[i]-v[i];
            y[i]=v[i]-w[i];
            e[i].id=i;
            e[i].val=x[i];
            f[i].id=i;
            f[i].val=y[i];
            cnt[pos[i]]++;
            ans+=u[i];
        }
        update();
        if(maxsz>n/2){
            d=maxsz-n/2;
            sort(e+1,e+n+1,cmp);
            int j=0;
            int g;
            for(int i=1;i<=n&&j<d;i++){
                g=e[i].id;
                if(pos[g]!=maxps)continue;
                ans-=x[g];
                pos[g]=ord[g][2];
                j++;
            }
        }
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=cnt[4]=0;
        for(int i=1;i<=n;i++){
            cnt[pos[i]]++;
        }
        update();
        if(maxsz>n/2){
            d=maxsz-n/2;
            for(int i=1;i<=n;i++){
                if(pos[i]==ord[i][2])ext[i]=1;
            }
            sort(f+1,f+n+1,cmp);
            int j=0;
            int g;
            for(int i=1;i<=n&&j<d;i++){
                g=e[i].id;
                if(!ext[g])continue;
                if(pos[g]!=maxps)continue;
                ans-=y[g];
                pos[g]=ord[g][3];
                j++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
