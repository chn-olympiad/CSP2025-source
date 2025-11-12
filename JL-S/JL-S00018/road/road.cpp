#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
struct r{
int a;
int b;
int c;
};
bool operator >(r a,r b){
    return a.c>b.c;
}
vector<r> R[1010];
priority_queue<r,vector<r>,greater<r> > q,p;
int n,m,k;
int ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool b[1010];
    memset(b,0,sizeof(b));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        R[a].push_back({a,b,c});
        R[b].push_back({a,b,c});
        q.push({a,b,c});
    }
    r x=q.top();
    b[x.a]=true;
    b[x.b]=true;
    ans+=x.c;
    for(int i=0;i<R[x.a].size();i++)
        p.push(R[x.a][i]);
    for(int i=0;i<R[x.b].size();i++)
        p.push(R[x.b][i]);
    int cnt=2;
    while(cnt!=m){
        x=p.top();
        p.pop();
        if(b[x.a]&&b[x.b]) continue;
        ans+=x.c;
        for(int i=0;i<R[x.b].size();i++)
            p.push(R[x.b][i]);
        b[x.b]=true;
        cnt++;
    }
    cout<<ans;
    return 0;
}

//
