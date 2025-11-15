#include  <bits/stdc++.h>
using namespace std;
ifstream in("club.in");
ofstream out("club.out");
using ll = long long;
int maxx(ll a,ll b,ll c){
    return max(a,max(b,c));
}
void solve(){
    ll n;
    in>>n;
    vector<vector<ll>> a(n,vector<ll>(3));
    for(int i=0;i<n;i++)    in>>a[i][0]>>a[i][1]>>a[i][2];

    long long ans=0;
    vector<vector<int>> mem(3);
    for(int i=0;i<n;i++){
        if(maxx(a[i][0],a[i][1],a[i][2])==a[i][0]){
            ans+=a[i][0];
            mem[0].push_back(i);
        }else if(maxx(a[i][0],a[i][1],a[i][2])==a[i][1]){
            ans+=a[i][1];
            mem[1].push_back(i);
        }else{
            ans+=a[i][2];
            mem[2].push_back(i);
        }
    }

    if(mem[0].size()>n/2){
        vector<ll> hi;
        int need=mem[0].size()-n/2;

        for(int i=0;i<mem[0].size();i++){
            int ind=mem[0][i];
            hi.push_back(min(a[ind][0]-a[ind][1], a[ind][0]-a[ind][2]));
        }

        sort(hi.begin(),hi.end());

        for(int i=0;i<need;i++) ans-=hi[i];
    }else if(mem[1].size()>n/2){
        vector<ll> hi;
        int need=mem[1].size()-n/2;

        for(int i=0;i<mem[1].size();i++){
            int ind=mem[1][i];
            hi.push_back(min(a[ind][1]-a[ind][0], a[ind][1]-a[ind][2]));
        }

        sort(hi.begin(),hi.end());

        for(int i=0;i<need;i++) ans-=hi[i];
    }else if(mem[2].size()>n/2){
        vector<ll> hi;
        int need=mem[2].size()-n/2;

        for(int i=0;i<mem[2].size();i++){
            int ind=mem[2][i];
            hi.push_back(min(a[ind][2]-a[ind][1], a[ind][2]-a[ind][0]));
        }

        sort(hi.begin(),hi.end());

        for(int i=0;i<need;i++) ans-=hi[i];
    }

    out<<ans<<'\n';
}

int main(){
    
    int t;
    in>>t;
    while(t--)  solve();

    return 0;
}