#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct sut{
    int x,y;
}s[1100005];
int f[15005];
int findf(int x){
    if(f[x]==x){
        return x;
    }
    f[x]=findf(f[x]);
    return f[x];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for(int i=1;i<=n+k;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        s[i].x=x;
        s[i].y=y;
        pair<int,int> pp;
        pp.first=w;
        pp.second=i;
        q.push(pp);
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            s[m+(i-1)*n+j].x=i+n;
            s[m+(i-1)*n+j].y=j;
            pair<int,int> pp;
            pp.first=w;
            pp.second=m+(i-1)*n+j;
            q.push(pp);
        }
    }
    int bian=0,ans=0;
    while(bian<n+k-1){
        int l=q.top().second,w=q.top().first;
        q.pop();
        int x=s[l].x,y=s[l].y;
        int zx=findf(x),zy=findf(y);
        if(zx==zy){
            continue;
        }
        bian++;
        ans+=w;
        f[zx]=zy;
        //cout<<x<<" "<<y<<" "<<w<<endl;
        //for(int i=1;i<=n+k;i++){
        //    cout<<f[i]<<" ";
        //}
       //cout<<endl;
    }
    cout<<ans;
}
