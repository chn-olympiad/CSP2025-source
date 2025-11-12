#include<bits/stdc++.h>
using namespace std;
struct road{
    int from;
    int to;
    int cost;
    int id;
};
road r[2250000];
bool flag[2097152];
int a[16];
int n,m,k;
int cnt = 1;
int cntr = 0;
long long ans = 0;
bool cmp(road a,road b){
    return a.cost<b.cost;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    /// jian tu
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>r[cnt].from>>r[cnt].to>>r[cnt].cost;
        r[cnt].id = 0;
        cnt ++;
        r[cnt].from = r[cnt-1].to;
        r[cnt].to = r[cnt-1].from;
        r[cnt].cost = r[cnt-1].cost;
        r[cnt].id = 0;
        cnt ++;
    }
    for(int i=1;i<=k;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++){
            cin>>r[cnt].cost;
            r[cnt].cost += a[i];
            r[cnt].from = m+i;
            r[cnt].to = j;
            r[cnt].id = i;
            cnt ++;
            r[cnt].cost = r[cnt-1].cost;
            r[cnt].from = r[cnt-1].to;
            r[cnt].to = r[cnt-1].from;
            r[cnt].id = i;
            cnt ++;
        }
    }
    sort(r+1,r+cnt,cmp);
    /*for(int i=1;i<cnt;i++){
        cout<<r[i].from<<" "<<r[i].to<<" "<<r[i].cost<<" "<<r[i].id<<endl;
    }*/
    /// zui xiao sheng cheng shu
    for(int i=1;i<cnt;i++){
        if(flag[r[i].from]==1 && flag[r[i].to]==1){
            continue;
        }
        flag[r[i].from] = 1;
        flag[r[i].to] = 1;
        cntr ++;
        ans += r[i].cost;
        //cout<<r[i].from<<" "<<r[i].to<<endl;
        //cout<<"dsl"<<ans<<endl;
        if(r[i].id!=0){
            //cout<<"kkl"<<a[r[i].id]<<endl;
            r[i].cost -= a[r[i].id];
            for(int j=1;j<cnt;j++){
                if(j==i){
                    continue;
                }
                if(r[j].id==r[i].id){
                    r[j].id = 0;
                    r[j].cost -= a[r[i].id];
                }
            }
            r[i].id = 0;
            n ++;
            sort(r+1,r+cnt,cmp);
            /*for(int i=1;i<cnt;i++){
                cout<<r[i].from<<" "<<r[i].to<<" "<<r[i].cost<<" "<<r[i].id<<endl;
            }*/
        }
        if(cntr==n-1){
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}
