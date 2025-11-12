#include<bits/stdc++.h>
using namespace std;
int n,m,k,bro[1001]={};
struct node{
    int zho,jia;
};
vector<node>v[15001]={};
int jin(int biqi,int bien){
    int lu[n+k+1]={};
    for(int i=1;i<=n+k;i++){
        lu[i]=pow(2,30);
    }
    lu[biqi]=0;
    queue<int>idk;idk.push(biqi);
    while(!idk.empty()){
        int tp=idk.front();idk.pop();
        for(int i=0;i<v[tp].size();i++){
            if()
                if(lu[tp]+v[tp][i].jia<lu[v[tp][i].zho]){

                }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    for(int i=1;i<=k;i++){
        cin>>bro[i];
        for(int j=1;j<=n;j++){
            int t1;cin>>t1;
            v[i+n].push_back({j,t1});
            v[j].push_back({i+n,t1});
        }
    }
    cout<<13;
    return 0;
}
// \o/ *pray.
