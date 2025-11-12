#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int k=1,s=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') k=-k;
    for(;isdigit(c);c=getchar()) s=(s<<1)+(s<<3)+(c^48);
    return k*s;
}
const int N=1e5+5;
int n,maxn,cnt[N],d[N],a[N][4],ans,res;
// int flag1;
// int tmp[N];
// void dfs(int u){
//     if(u>n){
//         int res=0;
//         for(int i=1;i<=n;++i){
//             res+=a[i][d[i]];
//         }
//         // if(res>ans){
//         //     printf("res=%d\n",res);
//         //     for(int i=1;i<=n;++i){
//         //         printf("d[%d]=%d ",i,d[i]);
//         //     }
//         //     printf("\n");
//         // }
//         ans=max(ans,res);
//         return;
//     }
//     for(int j=1;j<=3;++j){
//         if(cnt[j]>=maxn) continue;
//         d[u]=j;
//         cnt[j]++;
//         dfs(u+1);
//         cnt[j]--;
//     }
// }
// void wk1(){
//     for(int i=1;i<=n;++i) tmp[i]=a[i][1];
//     sort(tmp+1,tmp+1+n);
//     for(int i=n;i>maxn;--i){
//         ans+=tmp[i];
//     } 
//     cout<<ans<<'\n';
// }
struct node{
    int id,w,nxt;
    bool operator<(const node &tmp)const{//按影响最小来排序
        return w-nxt<tmp.w-tmp.nxt;
    }
}w[N];
vector<node> v[4];int sum[4];
void wk2(){
    for(int i=0;i<=3;++i) sum[i]=0,v[i].clear();
    for(int i=1;i<=n;++i){
        int maxn=max(max(a[i][1],a[i][2]),a[i][3]);
        if(maxn==a[i][1]){ 
            int x=a[i][2],y=a[i][3];
            v[1].push_back({i,a[i][1],max(a[i][2],a[i][3])});
            sum[1]+=a[i][1];
        }
        else if(maxn==a[i][2]){
            v[2].push_back({i,a[i][2],max(a[i][1],a[i][3])});
            sum[2]+=a[i][2];
        }
        else{
            v[3].push_back({i,a[i][3],max(a[i][2],a[i][1])});
            sum[3]+=a[i][3];
        }
    }
    if(v[1].size()<=maxn && v[2].size()<=maxn && v[3].size()<=maxn){
        ans=sum[1]+sum[2]+sum[3];
        cout<<ans<<'\n';
        return;
    }
    if(v[1].size()>maxn){
        sort(v[1].begin(),v[1].end());
        int cnt=v[1].size()-maxn;
        for(int i=0;i<v[1].size();++i){
            node now=v[1][i];
            sum[1]-=now.w;ans+=now.nxt;
            cnt--;
            if(!cnt) break;
        }
    }    
    if(v[2].size()>maxn){
        sort(v[2].begin(),v[2].end());
        int cnt=v[2].size()-maxn;
        for(int i=0;i<v[2].size();++i){
            node now=v[2][i];
            sum[2]-=now.w;ans+=now.nxt;
            cnt--;
            if(!cnt) break;
        }
    }    
    if(v[3].size()>maxn){
        sort(v[3].begin(),v[3].end());
        int cnt=v[3].size()-maxn;
        for(int i=0;i<v[3].size();++i){
            node now=v[3][i];
            sum[3]-=now.w;ans+=now.nxt;
            cnt--;
            if(!cnt) break;
        }
    }
    ans+=sum[1]+sum[2]+sum[3];
    // for(int i=1;i<=3;++i) printf("sum[%d]=%d ",i,sum[i]);
    // printf("ans=%d\n",ans);
    cout<<ans<<'\n';
}
void solve(){
    ans=0;
    n=read();maxn=n/2;
    // flag1=0;int tag=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j) a[i][j]=read();
        // if(a[i][2]!=0 || a[i][3]!=0) flag1=1;
        // if(a[i][3]!=0) tag=0;
    }
    // cout<<"f1="<<flag1<<'\n';
    wk2();return;//简直是心态王 17：19 才切T1
    // if(!flag1){
    //     wk1();
    //     return;
    // }
    // else if(n>10){
    //     wk2();
    //     return;
    // }
    // else{
    //     dfs(1);
    //     cout<<ans<<'\n';//怎么办T1只有暴力，一个小时啥也没想到
    // }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int T=read();T;T--) solve();
    return 0;
}
/*
2
6
4 2 0
3 2 0
5 3 0
3 5 0
15 0 0
3 0 0
4
4 0 0
3 0 0
15 0 0
13 0 0

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

147325
*/
//Ren5Jie4Di4Ling5%