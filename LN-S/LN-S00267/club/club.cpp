#include<bits/stdc++.h>
using namespace std;
struct P{
    int i,v;
    bool operator<(const P aa)const{
        return v<aa.v;
    }
}c1[100005],c2[100005],c3[100005];
int T,n,a[100005][4],t[100005],nxt[100005],cnt[4],ans,k1;
int maxi(int aa,int bb,int cc){
    if(aa>bb){
        if(aa>cc){
            return 1;
        }
        return 3;
    }
    else{
        if(bb>cc){
            return 2;
        }
        return 3;
    }
}
void do1(){
    int k=cnt[1]-(n>>1);
    sort(c1+1,c1+1+cnt[1]);
    while(k--){
        ans-=c1[k+1].v;
    }
}
void do2(){
    int k=cnt[2]-(n>>1);
    sort(c2+1,c2+1+cnt[2]);
    while(k--){
        ans-=c2[k+1].v;
    }
}
void do3(){
    int k=cnt[3]-(n>>1);//cout<<k;
    sort(c3+1,c3+1+cnt[3]);
    while(k--){
        ans-=c3[k+1].v;//cout<<ans<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);ans=0;cnt[1]=0;cnt[2]=0;cnt[3]=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);t[i]=0;nxt[i]=0;
            k1=maxi(a[i][1],a[i][2],a[i][3]);
            if(k1==1){
                if(a[i][2]>a[i][3]){
                    t[i]=1;nxt[i]=2;
                    c1[++cnt[1]].i=i;c1[cnt[1]].v=a[i][1]-a[i][2];
                }
                else{
                    t[i]=1;nxt[i]=3;
                    c1[++cnt[1]].i=i;c1[cnt[1]].v=a[i][1]-a[i][3];
                }
                ans+=a[i][1];
            }
            else if(k1==2){
                if(a[i][1]>a[i][3]){
                    t[i]=2;nxt[i]=1;
                    c2[++cnt[2]].i=i;c2[cnt[2]].v=a[i][2]-a[i][1];
                }
                else{
                    t[i]=2;nxt[i]=3;
                    c2[++cnt[2]].i=i;c2[cnt[2]].v=a[i][2]-a[i][3];
                }
                ans+=a[i][2];
            }
            else{
                if(a[i][1]>a[i][2]){
                    t[i]=3;nxt[i]=1;
                    c3[++cnt[3]].i=i;c3[cnt[3]].v=a[i][3]-a[i][1];//cout<<c3[cnt[3]].v<<endl;
                }
                else{
                    t[i]=3;nxt[i]=2;
                    c3[++cnt[3]].i=i;c3[cnt[3]].v=a[i][3]-a[i][2];//cout<<c3[cnt[3]].v<<endl;
                }
                ans+=a[i][3];
            }
        }
        if(cnt[1]>(n>>1)){
            do1();
        }
        else if(cnt[2]>(n>>1)){
            do2();
        }
        else if(cnt[3]>(n>>1)){
            do3();
        }
        printf("%d\n",ans);
    }

    return 0;
}
