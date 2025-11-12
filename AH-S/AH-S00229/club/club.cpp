#include <bits/stdc++.h>
using namespace std;
int max(int a,int b,int c){return max(a,max(b,c));}
vector<vector<int>> a;
priority_queue<int,vector<int>,greater<int>> q[3];
int n,ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
int T;
cin>>T;
while(T--){
    cin>>n;
    a.resize(n,vector<int>(3));
    for(auto &p:a) cin>>p[0]>>p[1]>>p[2];
    for(auto &p:a){
        if(max(p[0],p[1],p[2])==p[0]){
            q[0].push(min(p[0]-p[1],p[0]-p[2]));
            ans+=p[0];
            while(q[0].size()>n/2) ans-=q[0].top(),q[0].pop();
        }
        else if(max(p[0],p[1],p[2])==p[1]){
            q[1].push(min(p[1]-p[0],p[1]-p[2]));
            ans+=p[1];
            while(q[1].size()>n/2) ans-=q[1].top(),q[1].pop();
        }
        else if(max(p[0],p[1],p[2])==p[2]){
            q[2].push(min(p[2]-p[0],p[2]-p[1]));
            ans+=p[2];
            while(q[2].size()>n/2) ans-=q[2].top(),q[2].pop();
        }
    }
    cout<<ans<<'\n';
    a.clear(); ans=0; n=0;
    while(q[0].size()) q[0].pop();
    while(q[1].size()) q[1].pop();
    while(q[2].size()) q[2].pop();
}
    return 0;
}
