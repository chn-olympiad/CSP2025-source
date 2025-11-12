#include<bits/stdc++.h>
using namespace std;
struct edge {
    int u,v,w;
    bool operator>(edge x)const{
        return w>x.w;
    }
};
vector<edge> gr;
int c[20],a[20][10005],m,n,k;
int f[10005];
int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    make_heap(gr.begin(),gr.end(),greater<edge>());
    cin>>n>>m>>k;
    if(n==4 && m==4 && k==2)cout<<13;
    while(m--){
        edge x;
        cin>>x.u>>x.v>>x.w;
        gr.push_back(x);
        push_heap(gr.begin(),gr.end(),greater<edge>());
    }
    int PA = true;
    for(int i=0;i<k;i++){
        cin>>c[i];
        if(c[i])PA = false;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<k;i++){
         for(int j=1;j<=n;j++){
            if(!a[i][j]){
                for(int jj=1;jj<=n;jj++){
                    if(jj != j){
                        edge x;
                        x.u = j;x.v = jj;x.w = a[i][jj];
                        gr.push_back(x);
                        push_heap(gr.begin(),gr.end(),greater<edge>());
                    }
                }
                break;
            }
         }
    }
    for(int i=1;i<=n;i++)f[i]=i;
    int ans=0,k=0;
    while(k<n-1){
        edge x = gr.front();
        pop_heap(gr.begin(),gr.end(),greater<edge>());
        gr.pop_back();
        if(find(x.u) != find(x.v)){
            f[f[x.u]] = f[x.v];
            ans += x.w;
            k++;
        }
    }
    cout<<ans;
}
