#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,nn;
map<int,vector<int> > mp;
int road[10011][10011],cit[11];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    nn=n+k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back(v);
        mp[v].push_back(u);
        road[u][v]=w;
        road[v][u]=w;
        ans+=w;
    }
    for(int i=0;i<k;i++){
        cin>>cit[i];
        ans+=cit[i];
        for(int j=0;j<n;j++){
            int p;
            cin>>p;
            mp[n+i].push_back(i);
            mp[i].push_back(n+i);
            road[n+i][i]=p;
            road[i][n+i]=p;
            ans+=p;
        }
    }
    for(int i=1;i<=nn;i++){
        int u=mp[i].size();
        for(int j=0;j<u;j++){
            for(int k=j+1;k<u;k++){
                if(road[mp[i][j]][mp[i][k]]!=0){
                    int mx=max(road[i][mp[i][j]],max(road[i][mp[i][k]],road[mp[i][j]][mp[i][k]]));
                    if(road[i][mp[i][j]]==mx){
                        road[i][mp[i][j]]=0;
                        road[mp[i][j]][i]=0;
                    }
                    else if(road[i][mp[i][k]]==mx){
                        road[i][mp[i][k]]=0;
                        road[mp[i][k]][i]=0;
                    }
                    else if(road[mp[i][j]][mp[i][k]]==mx){
                        road[mp[i][j]][mp[i][k]]=0;
                        road[mp[i][k]][mp[i][j]]=0;
                    }
                    ans-=mx;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

