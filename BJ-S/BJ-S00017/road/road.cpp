#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int fa[maxn],c[maxn];
struct posd{
    int from,to,dis;
}s[maxn];
vector<int >ci[maxn];
int find(int x){
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y){
    fa[find(x)]=find(y);
    return;
}
bool cmp(posd a,posd b){
    return a.dis<b.dis;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,wi;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>wi;
        s[i].from=x;
        s[i].to=y;
        s[i].dis=wi;
    }
    fa[0]=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int i=1;i<=n;i++){
            fa[i]=i;
            cin>>wi;
            ci[i].push_back(wi);
        }
    }
    sort(s+1,s+m+1,cmp);
    long long ans=0;
    for(int i=1;i<=m;i++){
        x=find(s[i].from),y=find(s[i].to);
        if(x!=y){
            merge(s[i].from,s[i].to);
            ans+=s[i].dis;
        }
        else
            continue;
    }
    cout<<ans;
    return 0;
}
