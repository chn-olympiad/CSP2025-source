#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+1e5+10;
int n,m,k;
vector<pair<int,pair<int,int> > >e,g;
int c[20];
int a[20][N];
int fa[N],sz[N];
long long ans=1e18;
int fl=0;
int find(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(sz[x]>sz[y]){
        swap(x,y);
    }
    fa[x]=y;
    sz[y]+=sz[x];
}
long long f(int fn){
    for(int i=1;i<=n+10;i++){
        fa[i]=i;
        sz[i]=1;
    }
    fn--;
    long long re=0;
    for(pair<int,pair<int,int> > i : g){
        if(find(i.second.first)!=find(i.second.second)){
            merge(i.second.first,i.second.second);
            re+=i.first;
            fn--;
        }
        if(fn==0){
            break;

        }
    }
    return re;
}
bool cmp(pair<int,pair<int,int> > a1, pair<int,pair<int,int> > a2){
    return a1.first<a2.first;

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e.push_back(make_pair(w,make_pair(u,v)));
    }
    for(int i=1;i<=k;i++){
        int ff=0;
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(c[i]==0&&a[i][j]==0){
                ff=1;
            }
        }
        fl+=ff;
    }
    if(fl==k){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==0){
                    for(int p=1;p<=n;p++){
                        e.push_back(make_pair(a[i][p],make_pair(j,p)));
                    }
                    break;
                }
            }
        }
        sort(e.begin(),e.end());
        g=e;
        cout<<f(n+k+100)<<endl;
        return 0;
    }
    sort(e.begin(),e.end());
    for(int i=0;i<1<<k;i++){
        g.clear();
        vector<pair<int,pair<int,int> > > vc;
        vc.clear();
        long long sc=0;
        int sm=0;
        for(int j=1;j<=k;j++){
            if(i>>(j-1)&1){
                sc+=c[j];
                sm++;
                for(int p=1;p<=n;p++){
                    vc.push_back(make_pair(a[j][p],make_pair(n+j,p)));
                }
            }
        }
        sort(vc.begin(),vc.end());
        int vi=0,fi=0;
        while(1){
            if(vi>=vc.size()&&fi>=e.size()){
                break;
            }
            if(vi>=vc.size()){
                g.push_back(e[fi]);
                fi++;
            }else if(fi>=e.size()){
                g.push_back(vc[vi]);
                vi++;
            }else{
                if(vc[vi]<e[fi]){
                    g.push_back(vc[vi]);
                    vi++;
                }else{
                    g.push_back(e[fi]);
                    fi++;
                }
            }
        }
        ans=min(ans,sc+f(n+sm));
    }
    cout<<ans<<endl;
    return 0;
}
