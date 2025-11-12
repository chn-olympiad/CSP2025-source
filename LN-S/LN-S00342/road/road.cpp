#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int size=10086;
struct side{
    int st,ed,num;
    bool operator<(side _2){
        return num<_2.num;
    }
};
int l[size];
vector<side>g;
int f[size];
int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y){
    if(find(x)==find(y))return;
    f[f[x]]=f[y];
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,x,y,z,c;
    cin>>n>>m>>k;//ignore k as 0 for the rest of the program to solve
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        g.push_back({x,y,z});//side arrays consider a side as a double-side here
    }
    //Mininum tree
    for(int i=0;i<size;i++)f[i]=i;
    //How to solve A?
    /*int same;
    for(int i=0;i<n;i++){
        cin>>l[i];
        if(l[i]==0)same=i;
    }
    for(int i=0;i<n;i++){
        if(i!=same)g.push_back({same,i,l[i]});//distance to self is always 0
    }
    /*
    //How to solve A?
    int same;
    for(int i=0;i<n;i++){
        cin>>l[i];
        if(l[i]==0)same=i;
    }
    for(int i=0;i<n;i++){
        if(i!=same)g.push_back({same,i,l[i]});//distance to self is always 0
    }
    */
    sort(g.begin(),g.end());
    int ans=0;
    for(int i=0;i<g.size();i++){
        if(find(g[i].st)==find(g[i].ed))continue;
        else{
            ans+=g[i].num;
            merge(g[i].st,g[i].ed);
        }
    }
    cout<<ans;
    return 0;
}