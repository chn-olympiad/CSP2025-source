#include<iostream>
#include<map>
#include<queue>
typedef long long ll;
using namespace std;
struct node{
    ll u,v,w;
    bool operator<(const node x)const{
        return w>x.w;
    }
};
priority_queue<node> q;
ll f[10005],deep[10005],countryside[15][10005],c[15],ans,n,m,u[1000005],v[1000005],w[1000005],k,ccnt;
bool yby[15];
ll find(ll x){
    if(f[x]==x){
        return x;
    }
    return f[x]=find(f[x]);
}
void merge(ll x,ll y){
    f[find(x)]=find(y);
}
ll zxscs(){
    ll cnt=0,aans=0;
    while(cnt<ccnt-1){
        node f=q.top();
        q.pop();
        if(find(f.u)==find(f.v)){
            continue;
        }
        merge(f.u,f.v);
        aans+=f.w;
        cnt++;
    }
    return aans;
}
void dfs(ll x){
    //cout<<x<<endl;
    if(x==k+1){
        while(!q.empty()){
            q.pop();
        }
        for(ll i=1;i<=ccnt;i++){
            f[i]=i;
        }
        for(ll i=1;i<=m;i++){
            q.push({u[i],v[i],w[i]});
            //cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
        }
        ccnt=n;
        ll sum=0;
        for(ll i=1;i<=k;i++){
            if(yby[i]==true){
                ccnt++;
                sum+=c[i];
                for(ll j=1;j<=n;j++){
                    q.push({ccnt,j,countryside[i][j]});
                    //cout<<ccnt<<" "<<j<<" "<<countryside[i][j]<<endl;
                }
            }
        }
        sum+=zxscs();
        ans=min(ans,sum);
        return;
    }
    dfs(x+1);
    yby[x]=1;
    ccnt++;
    dfs(x+1);
    ccnt--;
    yby[x]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    bool flag=true;
    for(ll i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0){
            flag=false;
        }
        for(int j=1;j<=n;j++){
            cin>>countryside[i][j];
        }
    }
    if(flag==true){
        ccnt=n+k;
        for(ll i=1;i<=ccnt;i++){
            f[i]=i;
        }
        for(ll i=1;i<=m;i++){
            q.push({u[i],v[i],w[i]});
            //cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
        }
        ccnt=n;
        for(ll i=1;i<=k;i++){
            ccnt++;
            for(ll j=1;j<=n;j++){
                q.push({ccnt,j,countryside[i][j]});
            }
        }
        cout<<zxscs()<<endl;
        return 0;
    }
    ans=0x3f3f3f3f;
    ccnt=n;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
