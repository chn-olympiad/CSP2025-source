#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,s;
};
vector <node>G[10100];
int u,v,s;
int n,m,k,minn=1e9,fw;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>u>>v>>s;
        node si={v,s};
        G[u].push_back(si);
    }
    for(int i=0;i<k;i++){
        cin>>s;
        for(int i=0;i<n;i++){
            cin>>fw;
        }
        if(minn>s){
            minn=s;
        }
    }
    cout<<minn<<endl;
    return 0;
}
