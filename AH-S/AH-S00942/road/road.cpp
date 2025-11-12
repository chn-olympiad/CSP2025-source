#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=1e6+1;
int n,m,k,c[15],a[15][N],f[N];
long long ans;
struct node{
    int u,v,w;
}t[M+10*N];
vector<node>g[N];
bool cmp(node x,node y){
    return x.w<y.w;
}
int fi(int x){
    if(x!=f[x]){
        return f[x]=fi(f[x]);
    }else{
        return x;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int sum=m;
    for(int i=1;i<=m;i++){
        cin>>t[i].u>>t[i].v>>t[i].w;
        if(t[i].u>t[i].v)swap(t[i].u,t[i].v);
        //g[t[i].u].push_back(t[i]);
        //node p=t[i];
        //swap(p.u,p.v);
        //g[t[i].v].push_back(p);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            t[++sum].u=i;
            t[sum].v=j;
            t[sum].w=a[i][j];
            if(t[sum].u>t[sum].v)swap(t[sum].u,t[sum].v);
        }
    }
    sort(t+1,t+sum+1,cmp);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    //for(int i=1;i<=sum;i++){
    //    cout<<t[i].u<<" "<<t[i].v<<" "<<t[i].w<<"\n";
    //}
    for(int i=1;i<=sum;i++){
        int x=t[i].u,y=t[i].v;
        if(f[x]!=f[y]){
            x=fi(x);
            y=fi(y);
            f[min(x,y)]=max(x,y);
            ans+=t[i].w;
            //cout<<i<<" ";
        }
        //cout<<"di"<<i<<"lun:f[]={";
        //for(int i=1;i<n;i++){
        //    cout<<f[i]<<",";
        //}
        //cout<<f[n]<<"}\n";
    }
    //cout<<"\n";
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
