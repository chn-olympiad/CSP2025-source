#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[4];
struct node{
    int val,id;
};
struct people{
    int v1,v2,v3,mv,mid1,old;
}p[100050];
bool cmp(node a,node b){
    return a.val>b.val;
}
bool cmp2(people a,people b){
    return a.mv<b.mv;
}
int a[100050][4];
vector<people> man[4];
ll an=0;
int n;
bool join[100050];//是否加入社团
void dfs(int now,int c1,int c2,int c3,ll sum){//n较小时,采用DFS
    if(c1>n/2||c2>n/2||c3>n/2) return;
    if(now>n){
        an=max(an,sum);
        return;
    }
    dfs(now+1,c1+1,c2,c3,sum+a[now][1]);
    dfs(now+1,c1,c2+1,c3,sum+a[now][2]);
    dfs(now+1,c1,c2,c3+1,sum+a[now][3]);
}
void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        int k[3]={a[i][1],a[i][2],a[i][3]};
        sort(k,k+3);
        p[i].v1=a[i][1];
        p[i].v2=a[i][2];
        p[i].v3=a[i][3];
        p[i].mv=k[2];
        p[i].mid1=(k[2]==a[i][1]?1:(k[2]==a[i][2]?2:3));
        p[i].old=i;
    }
    an=0;
    dfs(0,0,0,0,0);
    cout<<an<<"\n";
    return;
    // sort(p+1,p+n+1,cmp2); 
    // ll ans=0; 
    // cnt[1]=cnt[2]=cnt[3]=0;
    // for(int i=1;i<=n;i++){
    //     cnt[p[i].mid1]++;
    //     man[p[i].mid1].push_back(p[i]);
    // }
    // sort(man[1].begin(),man[1].end(),cmp2);
    // sort(man[2].begin(),man[2].end(),cmp2);
    // sort(man[3].begin(),man[3].end(),cmp2);
    // for(int a1=0;a1<=n/2;a1++){
    //     for(int a2=0;a2<=n/2;a2++){
    //         for(int a3=0;a3<=n/2;a3++){
    //             if(a1+a2+a3==n){
    //                 ll tot=0;
    //                 for(int i=0;i<a2;i++){
    //                     if(!join[man[2][i].old]) tot+=man[2][i].mv,join[man[2][i].old]=1;
    //                 } 
    //                 for(int i=0;i<a3;i++){
    //                     if(!join[man[3][i].old]) tot+=man[3][i].mv,join[man[3][i].old]=1;
    //                 }
    //                 for(int i=0;i<a1;i++){
    //                     if(!join[man[1][i].old]) tot+=man[1][i].mv,join[man[1][i].old]=1;
    //                 }
    //                 ans=max(ans,tot);
    //             }
    //         }
    //     }
    // }
    // cout<<ans<<"\n";
    // if(cnt[1]>n/2){
    //     int las=cnt[1]-n/2;
    //     for(int i=man[1].size()-1;i>=man[1].size()-las;i--){
    //         man[man[1][i].mid2].push_back(man[1][i]);
    //         man[1].pop_back();
    //         cnt[man[1][i].mid2]++;
    //     }
    //     if(cnt[2]>n/2){

    //     }
    //}
    
    // int now=1;
    // while(now<=n){
    //     node b[3]={{p[now].v1,1},{p[now].v2,2},{p[now].v3,3}};
    //     sort(b,b+3,cmp);
    //     int fir=b[0].val,sec=b[1].val,thr=b[2].val;
    //     int id1=b[0].id,id2=b[1].id,id3=b[2].id;
    //     if(cnt[id1]<n/2){//最大
    //         joi[now]=1;
    //         cnt[id1]++;
    //         ans+=fir;
    //         now++;
    //     }
    //     if(cnt[id2]<n/2){//次大
    //         joi[i]=1;
    //         cnt[id2]++;
    //         ans+=sec;
    //         //printf("%d in club%d\n",p[i].old,id2);
    //         continue;
    //     }
    //     if(cnt[id3]<n/2){//最小
    //         joi[i]=1;
    //         cnt[id3]++;
    //         ans+=thr;
    //         //printf("%d in club%d\n",p[i].old,id3);
    //         continue;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     node b[3]={{p[i].v1,1},{p[i].v2,2},{p[i].v3,3}};
    //     sort(b,b+3,cmp);
    //     int fir=b[0].val,sec=b[1].val,thr=b[2].val;
    //     int id1=b[0].id,id2=b[1].id,id3=b[2].id;
    //     if(cnt[id1]<n/2){//最大
    //         join[i]=1;
    //         cnt[id1]++;
    //         ans+=fir;
    //         //printf("%d in club%d\n",p[i].old,id1);
    //         continue;
    //     }
    //     if(cnt[id2]<n/2){//次大
    //         join[i]=1;
    //         cnt[id2]++;
    //         ans+=sec;
    //         //printf("%d in club%d\n",p[i].old,id2);
    //         continue;
    //     }
    //     if(cnt[id3]<n/2){//最小
    //         join[i]=1;
    //         cnt[id3]++;
    //         ans+=thr;
    //         //printf("%d in club%d\n",p[i].old,id3);
    //         continue;
    //     }
    // }
    // printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}