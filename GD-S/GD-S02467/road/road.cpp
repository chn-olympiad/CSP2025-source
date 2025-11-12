#include<bits/stdc++.h>
using namespace std;
struct ver{
    int s,t;
    long long v;
};
bool operator> (ver a,ver b){
return a.v>b.v;}
int n,m,k;
vector<ver> w[10000];
long long c[10];
long long a[10][10000];
bool u[10000];
priority_queue<ver,vector<ver>,greater<ver>> q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;++i) u[i]=0;
    for(long long i=0,a,b,c;i<m;++i){
        cin>>a>>b>>c;
        w[a].push_back({a,b,c});
        w[b].push_back({a,b,c});
    }
    for(int i=0;i<k;++i){
        cin>>c[i];
        for(int j=0;j<n;++j) cin>>a[i][j];
    }
    for(int i=0;i<w[0].size();++i) q.push(w[0][i]);
    for(long long i=1,r=10000000000;i<n;++i){
        for(int j=0;j<k;++j) r=min(r,a[j][0]+a[j][i]);
        q.push({0,i,r});
    }
    ver m;
    int mm;
	long long ans=0;
    u[0]=1;
    while(n>0){
        m=q.top();
        q.pop();
        if(u[m.t]) continue;
		mm=m.t; 
        u[mm]=1;
        for(int i=0;i<w[mm].size();++i){
            if(!u[w[mm][i].t])
                q.push(w[mm][i]);
        }
        for(long long i=1,r=10000000000;i<n;++i){
            if(!u[i]){
                for(int j=0;j<k;++j) r=min(r,a[j][mm]+a[j][i]);
                q.push({0,i,r});
            }
        }
        ans+=m.v;
        --n;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
