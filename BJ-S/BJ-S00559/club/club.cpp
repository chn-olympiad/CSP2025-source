#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100013][4]={0};
int vis[100013][4]={0};
int club[114514]={0};
int cha[100013][4][4]={0};
bool cmp(int a,int b){
    if(a==0&&b!=0)return 0;
    int i=club[a];
    int j=club[b];
    int mina=100000000,minb=10000000000;
    for(int k=1;k<=3;k++){
        if(k!=i&&!vis[a][k]){
            if(cha[a][i][k]<=mina){
                mina=cha[a][i][k];
            }
        }
        if(k!=j&&!vis[b][k]){
            if(cha[b][j][k]<=minb){
                minb=cha[b][j][k];
            }
        }
    }
    return mina<minb;
}
vector<int>q[4];
queue<int>work;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=3;i++)q[i].clear();
        int n;
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            cha[i][1][2]=a[i][1]-a[i][2];
            cha[i][1][3]=a[i][1]-a[i][3];
            cha[i][3][2]=a[i][3]-a[i][2];
            cha[i][2][3]=a[i][2]-a[i][3];
            cha[i][2][1]=a[i][2]-a[i][1];
            cha[i][3][1]=a[i][3]-a[i][1];
            int maxn=-1,id=-1;
            for(int j=1;j<=3;j++){
                if(a[i][j]>maxn){
                    maxn=a[i][j];
                    id=j;
                }
            }
            ans+=maxn;
            club[i]=id;
            vis[i][id]=1;
            q[id].push_back(i);
        }
        int cnt[4]={0};
        for(int i=1;i<=n;i++){
            cnt[club[i]]++;
        }
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2){
                work.push(i);
            }
        }
        int head[4]={0};
        while(!work.empty()){
            int u=work.front();
            work.pop();
            sort(q[u].begin()+head[u],q[u].end(),cmp);
            int mina=1e9+7,mem;
            int we=q[u][head[u]];
            for(int i=1;i<=3;i++){
                if(i!=u&&!vis[we][i]&&cha[we][u][i]<mina){
                    mina=cha[we][u][i];
                    mem=i;
                }
            }
            club[we]=mem;
            cnt[mem]++;
            cnt[u]--;
            q[mem].push_back(we);
            vis[we][mem]=1;
            ans-=cha[we][u][mem];
            head[u]++;
            if(cnt[mem]>n/2)work.push(mem);
            if(cnt[u]>n/2)work.push(u);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
