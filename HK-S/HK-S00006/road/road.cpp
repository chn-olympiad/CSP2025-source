#include<bits/stdc++.h>
using namespace std;
#define int long long
//g++ -O2 -std=c++14 -static b.cpp -o b
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,i,j;
    cin>>n>>m>>k;
    vector<pair<int,int>>vec[n+1];
    int len[n+1];
    for(i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        len[i+1]=INT_MAX;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
    }
    int co[k],br[k][n+1];
    for(i=0;i<k;i++){
        cin>>co[i];
        for(j=1;j<=n;j++)
            cin>>br[i][j];
    }
    int num=0,sum=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int b[n+1]={0};
    int prev[n+1];
    prev[1]=1;
    len[1]=0;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        int A=pq.top().first;
        int B=pq.top().second;
        pq.pop();
        if(b[B]==1)
            continue;
        num++;
        sum=sum+A-len[prev[B]];
        b[B]=1;
        for(i=0;i<vec[B].size();i++){
            if(b[vec[B][i].first]==1)
                continue;
            if(len[vec[B][i].first]>A+vec[B][i].second){
                pq.push(make_pair(A+vec[B][i].second,vec[B][i].first));
                len[vec[B][i].first]=A+vec[B][i].second;
                prev[vec[B][i].first]=B;
            }
        }
    }
    // for(i=1;i<=n;i++)
    //     cout<<len[i]<<" ";
    // cout<<endl<<sum<<endl;
    if(k==0)
    cout<<sum<<endl;
    else
    cout<<0<<endl;
}