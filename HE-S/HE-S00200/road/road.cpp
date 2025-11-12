#include<bits/stdc++.h>
using namespace std;
//update:fuck kkk
//prime is best
//update 1024*100000*20 maybe pass?  pass ni ma le ge bi 24pts;
typedef pair<long long ,int > plii;

int n,m,k;
priority_queue <plii,vector<plii>,greater<plii>>pq;
int val[20];
plii ipt;
int vc[20][100020];
long long r[20];
struct e{
    int t,w;
};
e ed;
int a,b,c;
long long tsm=0;
long long cnt=0;
long long dis[100020];
bool vis[100020];
long long ans=0x7fffffffffffffff;
long long tl,tp;
int c4;
vector <e>ljb[100005];
long long solve(int b2){

    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    int nb=b2;
    int num=0;
    cnt=0;
    int o=0;
    for(int i=1;i<=1024;i*=2){
            o++;
        if(i&nb){cnt+=val[o];num--;}
        else{vis[o+n]=1;}
    }
    dis[1]=0;
    pq.push({0,1});
   // return 0;
    while((num!=n)){
        ipt=pq.top();
        pq.pop();
        if(vis[ipt.second])
            continue;
            num++;

        //tp=ipt.second;
        vis[ipt.second]=1;
        cnt+=ipt.first;
        //wr++;
        for(c4=0;c4<ljb[ipt.second].size();c4++)
        //for(e ed:ljb[ipt.second])
        {
            ed=ljb[ipt.second][c4];
            if(vis[ed.t])continue;
            if(ed.w<dis[ed.t]){
                dis[ed.t]=ed.w;
                pq.push({ed.w,ed.t});
            //    wr2++;
            }
         //   wr1++;
        }
       // cout<<ljb[tp].size()<<endl;
      //  wr3+=ljb[tp].size();
    }
    while(!pq.empty())
    pq.pop();
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        ljb[a].push_back({b,c});
        ljb[b].push_back({a,c});
    }
    for(int i=1;i<=k;i++){
        cin>>val[i];
        tsm+=val[i];
        for(int j=1;j<=n;j++){
                cin>>a;
            //scanf("%d",&a);
        ljb[n+i].push_back({j,a});
        ljb[j].push_back({n+i,a});
        }
    }
    if(k==0){
        cout<<solve(0);
        return 0;
    }
    if(k>5&&m>100000&&tsm==0){
        cout<<solve((1<<k)-1);
        return 0;
    }
    for(int i=0;i<(1<<k);i++){
        ans=min(solve(i),ans);
    }
    cout<<ans;
    //cout<<endl<<wr;
   // cout<<endl<<wr1;
    //cout<<endl<<wr2;
   // cout<<endl<<wr3;
    return 0;
}
