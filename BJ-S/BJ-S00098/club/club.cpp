#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,cnt[5];
struct ndd{int my,bm;}a[N][6];
bool cmp(ndd a,ndd b){
    if(a.my!=b.my)return a.my>b.my;
    return a.bm<b.bm;
}
struct nd{int dj,id,myd;};
struct cmpp{
    bool operator()(nd a,nd b){
        if(a.dj!=b.dj)return a.dj>b.dj;
        return a.id>b.id;
    }
};
priority_queue<nd,vector<nd>,cmpp > q[5];
void jr(int x,int bm,int my){
    int dj=a[x][my].my-a[x][my+1].my;
    nd now=q[bm].top();
    if(dj>=now.dj){
        ans=ans-now.dj+a[x][my].my;
        q[bm].pop();
        q[bm].push({dj,x,my});
        int id=now.id,myd=now.myd+1;
        if(cnt[a[id][myd].bm]<n/2){
            q[a[id][myd].bm].push({a[id][myd].my-a[id][myd+1].my,id,myd});
            cnt[a[id][myd].bm]++;

        }else{
            jr(id,a[id][myd].bm,myd);
        }
    }else{
        my++;
        bm=a[x][my].bm;
        if(cnt[bm]<n/2){
            ans+=a[x][my].my;
            q[bm].push({a[x][my].my-a[x][my+1].my,x,my});
            cnt[a[x][my].bm]++;
        }else{
            jr(x,bm,my);
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){

        while(!q[1].empty())q[1].pop();
        while(!q[2].empty())q[2].pop();
        while(!q[3].empty())q[3].pop();
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i][1].my >> a[i][2].my >> a[i][3].my;
        for(int i=1;i<=n;i++)a[i][1].bm=1,a[i][2].bm=2,a[i][3].bm=3,a[i][4].my=-1e9;
        ans=0;
        for(int i=1;i<=n;i++)sort(a[i]+1,a[i]+4,cmp);
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++){
            if(cnt[a[i][1].bm]<n/2){
                ans+=a[i][1].my;
                q[a[i][1].bm].push({a[i][1].my-a[i][2].my,i,1});
                cnt[a[i][1].bm]++;

            }
            else{
                jr(i,a[i][1].bm,1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
