#include<bits/stdc++.h>
#define int long long 
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
const int N=1e5+10;
int n;
void solve(){
    cin>>n;
    vector<int>d1,d2,d3;
    int sum=0;
    rep(i,1,n){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        if(v[2]==a) d1.push_back(v[2]-v[1]);
        else if(v[2]==b) d2.push_back(v[2]-v[1]);
        else if(v[2]==c) d3.push_back(v[2]-v[1]);
        sum+=v[2];
    }
    // cout<<sum<<' ';
    int m=n>>1;
    if((int)d1.size()>m){
        sort(d1.begin(),d1.end());
        rep(i,0,d1.size()-m-1){
            sum-=d1[i];
        }
    }else if((int)d2.size()>m){
        sort(d2.begin(),d2.end());
        rep(i,0,d2.size()-m-1){
            sum-=d2[i];
        }
    }else if((int)d3.size()>m){
        sort(d3.begin(),d3.end());
        rep(i,0,d3.size()-m-1){
            sum-=d3[i];
        }
    }
    cout<<sum<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();
    int T; 
    cin>>T;
    for(;T;--T){
        solve();
    }
    return 0;
}
/*
g++ club.cpp -o club -std=c++14 -O2 -Wall
*/