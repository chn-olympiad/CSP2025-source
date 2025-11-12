#include<bits/stdc++.h>
using namespace std;

int n,m,k;
pair<long long,pair<int,int> >edges[100005];
long long c[11];
long long a[11][10005];
int et=0;
int fa[10005];
int count=0;
vector<int> selected;
unsigned long long pre_sum=0;
unsigned long long ans=0;

void add_edge(int u,int v,long long wi){
    edges[et++]=make_pair(wi,make_pair(u,v));
}

int find(int node){
    if(fa[node]=node){
        return node;
    }else{
        fa[node]=find[fa[node]];
        return fa[node];
    }
}
void merge(int node1,int node2){
    fa[find(node2)]=find(node1);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    int u,v,wi;
    for(int i=0;i<m;i++){
        cin>>u>>v>>wi;
        add_edge(u,v,wi);
    }
    for(int i=0;i<k;i++){
        cin>>c[j];
        pre_sum+=c[j];
        for(int j=1;j<=n;i++){
            if (i==0){
                fa[j]=j;
            }
            cin>>a[i][j];
            pre_sum+=a[i][j];
        }
    }
    if (pre_sum==0){
        cout<<0<<endl;
        return 0;
    }
    sort(edges,edges+et);
    int ptr=0;
    int u,v;
    while(count<n-1){
        auto edge=edges+ptr;
        u=edge->second.first;
        v=edge->second.second;
        if(find(u)!=find(v)){
            ans+=edge->first;
            merge(u,v);
            selected.emplace_back(ptr);
            count++;
        }
        ptr++;
    }
    if(k==0){
        cout<<ans<<endl;
        return 0;
    }
}