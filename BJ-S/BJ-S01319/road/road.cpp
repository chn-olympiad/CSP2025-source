
#include<bits/stdc++.h>
using namespace std;
int n,k,m,c[10005],fa[10005],a[15][10005],ans;
struct edge{
    int fr,to,co;
}ed[1000005];
bool so(edge x,edge y){
    return x.co<=y.co;
}
vector<int> e[10005];
void shortest(){
    int lb=0,i=0;
    while(lb<n-1){
        while(fa[ed[i].to]==fa[ed[i].fr])i++;
        if(fa[ed[i].fr]!=ed[i].fr){
            fa[ed[i].to]=fa[fa[ed[i].fr]];
        }
        else{
            fa[ed[i].fr]=fa[fa[ed[i].to]];
        }
        ans+=ed[i].co;
        lb++;
        e[ed[i].fr].push_back(ed[i].to);
        e[ed[i].to].push_back(ed[i].fr);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>ed[i].fr>>ed[i].to>>ed[i].co;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            fa[j]=j;
        }
    }
    sort(ed,ed+m,so);
    shortest();
    cout<<ans;
    return 0;
}
