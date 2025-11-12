#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
struct p{
    long long v,w;
};
long long n,m,k,csh[20][N],s;
vector<p>q[N];
char zt='A';
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long u1,v1,w1;
        cin>>u1>>v1>>w1;
        q[u1].push_back({v1,w1});
        s+=w1;
    }
    for(long long i=1;i<=k;i++){
        for(long long j=1;j<=n+1;j++) cin>>csh[i][j];
        if(csh[i][1]!=0) zt='B';
    }
    cout<<s;
    return 0;
}
