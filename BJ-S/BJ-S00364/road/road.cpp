#include <bits/stdc++.h>
#define ing long long
using namespace std;
const int M = 2e4+5;
int n,m,k;
vector <pair<int,int> > mp[M];
int nw[10][M];
int ans = 0;
bool vis[M] = {0};
vector <pair <int,int> >cur;
void prim(int st){
    vis[st] = 1;
    for(auto i : mp[st]){
        if(vis[i.second])continue;
        cur.push_back(i);
    }
    sort(cur.begin(),cur.end());
    /*for(auto i : cur){
        cout<<i.second<<" ";
    }*/
    //cout<<endl;
    while(cur.begin()!=cur.end()){
        sort(cur.begin(),cur.end());
        pair <int,int> pii = *cur.begin();
        if(vis[pii.second]){
            cur.erase(cur.begin());continue;
        }
        /*for(auto i : cur){
            cout<<i.second<<" ";
        }*/
        //cout<<endl;
        vis[pii.second] = 1;
        //cout<<"-> "<<pii.second<<endl;
        ans+=pii.first;
        for(auto i : mp[pii.second]){
            if(vis[i.second])continue;
            cur.push_back(i);
        }
        cur.erase(cur.begin());
    }
    return;
}
void solve(){
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back(make_pair(c,b));
        mp[b].push_back(make_pair(c,a));
    }
    for(int i = 1;i<=k;i++){
        int c;
        cin>>c;
        nw[i][0] = c;
        for(int j = 1;j<=n;j++){
            int a;
            cin>>a;
            nw[i][j] = a;
        }
    }
    prim(1);
    cout<<ans;
    return;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T = 1;
    //cin>>T;
    while(T--)solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
