#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=1e6+3999;
int n,m,k;
long long ans=1e10*2;
bool vis[N];
vector<pair<int,int> > r[N];
int a,b,c;
/*
void bfs(int t,int v){
    bool flag=0;
    int i=0;
    while(r[t][i++].first()){
        flag=1;
        if(vis[t]!=1){
            vis[t]=1;
            bfs(r[t][i++].first())
            vis[t]=0;
        }
    }
    if(!flag){
        ans=min(ans,v);
    }
}*/
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        //r[a].push(make_pair(b,c));
        //r[b].push(make_pair(a,c));
    }

    for(int i=0;i<k;i++){
        cin>>c;
        if(c==0){
            cout<<0;
            return 0;
        }
    }
    //bfs(0,0);
    for(int i=0;i<n;i++){
        cin>>k;
        ans+=k;
    }
cout<<ans+c;











    return 0;
}
