#include<bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<=z;x++)
#define piii pair<int,pair<int,int> >
using namespace std;
const int N=1e4+20;
int n,m,k,nn;
ll ans=LLONG_MAX,num;
bool cs[15];
int c[15];
int cnt;
bool vis[N];
void dfs(int x,vector<vector<piii > >v){
    //cout<<x<<" "<<num<<endl;
    if(cnt==nn){
        //cout<<endl;
        ans=min(ans,num);
        return;
    }
    for(auto i:v[x]){
        if(!vis[i.first]){
            vis[i.first]=1;
            cnt++;
            int w=i.second.first;
            bool f=0;
            if(i.second.second&&!cs[i.second.second-n]){
                w+=c[i.second.second-n];
                cs[i.second.second-n]=1;
                nn++;
                f=1;
            }
            num+=w;
            dfs(i.first,v);
            num-=w;
            if(f){
                cs[i.second.second-n]=0;
                nn--;
            }
            vis[i.first]=0;
            cnt--;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    nn=n;
    vector<vector<piii > >v(n+20);
    f(i,1,m){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,{z,0}});
        v[y].push_back({x,{z,0}});
    }
    f(i,n+1,n+k){
        cin>>c[i-n];
        f(j,1,n){
            int a;
            cin>>a;
            v[i].push_back({j,{a,i}});
            v[j].push_back({i,{a,i}});
        }
    }
    cnt++;
    vis[1]=1;
    dfs(1,v);
    cout<<ans<<endl;
    return 0;
}
