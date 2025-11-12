#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
struct node{
    int x,y,num;
    bool operator<(const node &b) const{
        return y>b.y;
    }
};
priority_queue<node>q[3];
void clear(){
    ans=0;
    for(int i=0;i<3;i++) while(q[i].size()) q[i].pop();
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z,maxi,qwq,d;cin>>x>>y>>z;
        maxi=max(x,max(y,z));
        if(x==maxi) qwq=0,d=min(x-y,x-z);
        else if(y==maxi) qwq=1,d=min(y-x,y-z);
        else qwq=2,d=min(z-x,z-y);
        q[qwq].push({maxi,d,i});
    }
    for(int i=0;i<3;i++){
        if((int)q[i].size()<=n/2)
            while((int)q[i].size()) ans+=(ll)q[i].top().x,q[i].pop();
        else{
            while((int)q[i].size()>n/2) ans+=(ll)q[i].top().x-(ll)q[i].top().y,q[i].pop();
            while((int)q[i].size()) ans+=(ll)q[i].top().x,q[i].pop();
        }
    }
    cout<<ans<<'\n';
    clear();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}