#include <bits/stdc++.h>

using namespace std;

vector<pair<int,long long> > v[100005];
struct edge{
    int from,to;
    long long w;
    friend bool operator<(edge a,edge b){
        return a.w>b.w;
    }
};
priority_queue<edge> q;
int n;
int fa[100005];
int c[100005];

int getf(int x){
    if(x==fa[x])return x;
    return fa[x]=getf(fa[x]);
}

bool check(int xx,int yy){
    int fx=getf(xx);
    int fy=getf(yy);
    if(fx==fy)return true;
    return false;
}

void link(int xx,int yy){
    int fx=getf(xx);
    int fy=getf(yy);
    fa[fx]=fy;
}

long long geta(int pl){
    for(int i=1;i<=n+pl;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            q.push((edge){i,v[i][j].first,v[i][j].second});
        }
    }
    long long cnt=0;
    int num=0;
    while(!q.empty()){
        edge now=q.top();
        q.pop();
        if(check(now.from,now.to))continue;
        num++;
        cnt+=now.w;
        link(now.from,now.to);
        if(num==n+pl-1)break;
    }
    return cnt;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int f,t,w;
        cin>>f>>t>>w;
        v[f].push_back(make_pair(t,w));
        v[t].push_back(make_pair(f,w));
    }
    long long ans=geta(0);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int r;
            cin>>r;
            v[n+i].push_back(make_pair(j,r));
        }
    }
    //cout<<ans<<endl;
    for(int i=1;i<(1<<k);i++){
        int nn=i;
        int cnt=1;
        long long sum=0;
        while(!q.empty())q.pop();
        while(nn>0){
            if(nn%2==1){
                sum+=c[cnt];
                for(int j=0;j<v[n+cnt].size();j++){
                    q.push((edge){n+cnt,v[n+cnt][j].first,v[n+cnt][j].second});
                }
            }
            cnt++;
            nn/=2;
        }
        long long tt=sum+geta(cnt);
        ans=min(ans,tt);
        //cout<<tt<<endl<<endl;
    }
    cout<<ans<<endl;
	return 0;
}
