#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+2;
ll n,m,k,ans,pos[10002],conside[10002][12],lj;
struct node{
    int a,b,cost;
}s[N];
bool cmp(node x,node y){
    return x.cost<y.cost;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int sl=n;
    for(int i=1;i<=m;i++) cin>>s[i].a>>s[i].b>>s[i].cost;
    sort(s+1,s+m+1,cmp);
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>conside[j][i];
            if(conside[j][i]==0&&j!=0){
                if(pos[j]==1) lj=1;
                else{
                    pos[j]=1;
                    sl--;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(!lj&&sl==0){
            ans+=s[i].cost;
            lj=1;
            pos[s[i].a]=1,pos[s[i].b]=1;
            continue;
        }
        else if(sl==0){
            cout<<ans;
            return 0;
        }
        else{
            if((!pos[s[i].a])||(!pos[s[i].b])){
                if(!pos[s[i].a]&&pos[s[i].b]) sl--,pos[s[i].a]=1,lj=1;
                else if(pos[s[i].a]&&!pos[s[i].b]) sl--,pos[s[i].b]=1,lj=1;
                else sl-=2,pos[s[i].a]=1,pos[s[i].b]=1;
                ans+=s[i].cost;
            }
        }
    }
    cout<<ans;
    return 0;
}