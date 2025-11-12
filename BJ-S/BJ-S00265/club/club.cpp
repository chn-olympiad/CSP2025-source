#include <bits/stdc++.h>
using namespace std;
int t,n,a[200000][5],ans;
vector<int> vec[8];
struct node{
    int id,f,t,res;
};
vector<node> f;
int calc(int id,int f,int t){
    return abs(a[id][f]-a[id][t]);
}
bool cmp(node a,node b){
    return a.res<b.res;
}
bool vis[200000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        vec[1].clear(),vec[2].clear(),vec[3].clear();
        f.clear();
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            int maxn=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                maxn=max(maxn,a[i][j]);
            }
            ans+=maxn;
            // cout<<"ans+="<<maxn<<endl;
            if(maxn==a[i][1]){
                vec[1].push_back(i);
            }else if(maxn==a[i][2]){
                vec[2].push_back(i);
            }else {
                vec[3].push_back(i);
            }
        }
        int s=0;
        if(vec[1].size()>n/2) s=1;
        else if(vec[2].size()>n/2) s=2;
        else if(vec[3].size()>n/2) s=3;
        else{
            cout<<ans<<endl;
            continue;
        }
        // cout<<"s="<<s<<" tot="<<ans<<endl;
        for(int j=1;j<=3;j++){
            if(j!=s){
                for(int i=0;i<vec[s].size();i++){
                    f.push_back({vec[s][i],s,j,calc(vec[s][i],s,j)});
                }
            }
        }
        int cnt=0;
        int maxn=vec[s].size()-n/2;
        sort(f.begin(),f.end(),cmp);
        // for(auto it:f){
        //     cout<<"id:"<<it.id<<" s:"<<it.f<<" t:"<<it.t<<" res:"<<it.res<<endl;
        // }
        for(int i=0;i<f.size();i++){
            if(!vis[f[i].id]){
                // cout<<"put "<<f[i].id<<" from "<<f[i].f<<" to "<<f[i].t<<" by "<<f[i].res<<endl;
                vis[f[i].id]=1;
                ans-=f[i].res;
                cnt++;
                if(cnt==maxn) break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

