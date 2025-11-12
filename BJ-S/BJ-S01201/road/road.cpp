#include <bits/stdc++.h>
using namespace std;
struct st{
    int u=0,v=0;
    long long num=0;
}a[1000050],b[1000050],tool;
long long n,m,k,beside,vilige[15],zhengde[15],cntear,endans;
int f[1000050];
vector<st> dao[15];
vector<int> ear;
int hb(int x){
    if(f[x]==x) return x;
    return f[x]=hb(f[x]);
}
bool pd(int x,int y){
    hb(x);
    hb(y);
    if(f[x]!=f[y]) return 1;
    return 0;
}
bool cmp(st l,st r){
    return l.num<r.num;
}
bool fv[15];
int yong[15];
void pz(int x){
    if(x-1==cntear){
        long long city[10050]={};
        long long dans=0;
        for(int i=1;i<=cntear;i++){
            if(yong[i]==-1) continue;
            int y=yong[i];
            dans+=zhengde[y];
            //cout<<y<<endl;
            for(int j=0;j<dao[y].size();j++){
                if(city[dao[y][j].v]){
                    dans-=max(city[dao[y][j].v],dao[y][j].num);
                    city[dao[y][j].v]=min(city[dao[y][j].v],dao[y][j].num);
                }else{
                    city[dao[y][j].v]=dao[y][j].num;
                }
            }
        }
        //cout<<endl;
        //cout<<dans<<endl;
        endans=min(endans,beside-dans);
        return;
    }
    yong[x]=-1;
    pz(x+1);
    for(int i=0;i<cntear;i++){
        int z=ear[i];
        if(fv[z]) continue;
        fv[z]=1;
        yong[x]=z;
        pz(x+1);
        fv[z]=0;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    endans=INT_MAX;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].num;
    }
    for(int i=0;i<=k;i++){
        int cnt=n;
        long long ans=0;
        for(int j=1;j<=m;j++){
            b[j]=a[j];
            f[j]=j;
        }
        if(i>0){
            cin>>vilige[i];
            for(int j=1;j<=n;j++){
                cnt++;
                cin>>b[cnt].num;
                b[cnt].u=n+i;
                b[cnt].v=j;
                f[cnt]=cnt;
            }
        }

        sort(b+1,b+cnt+1,cmp);
        for(int j=1;j<=cnt;j++){
            int from=b[j].u,to=b[j].v;
            long long z=b[j].num;
            //cout<<from<<" "<<to<<" "<<f[from]<<" "<<f[to]<<endl;
            if(pd(from,to)){

                f[f[to]]=f[from];
                //cout<<f[from]<<" "<<f[to]<<endl;
                if(from>n){
                    tool.v=to;
                    tool.num=z;
                    dao[i].push_back(tool);
                }
                ans+=z;
            }
        }
        if(i==0) beside=ans;
        else{
            ans+=vilige[i];
        }
        endans=min(endans,ans);
    }
    cout<<endans;
    return 0;
}
