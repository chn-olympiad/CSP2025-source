#include<bits/stdc++.h>
using namespace std;
struct ll{
    int x,y;
    bool operator<(const ll &a)const{
        return y>a.y;
    }
};
vector<ll>v[5];
void solve(){
    v[1].clear(),v[2].clear(),v[3].clear();
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(x>=y&&x>=z){
            v[1].push_back({x,min(x-y,x-z)});
        }else if(y>=x&&y>=z){
            v[2].push_back({y,min(y-x,y-z)});
        }else{
            v[3].push_back({x,min(z-x,z-y)});
        }ans+=max(max(x,y),z);
    }for(int i=1;i<=3;i++){
        sort(v[i].begin(),v[i].end());
    }for(int i=1;i<=3;i++){
        while(v[i].size()>n/2){
            int x=v[i][v[i].size()-1].y;
            ans-=x;
            v[i].pop_back();
        }
    }cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
