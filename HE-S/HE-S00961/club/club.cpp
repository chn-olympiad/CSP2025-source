#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
int T;
int n;
ll a[N][3];
int cn[3];
vector<ll> val[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int op:{0,1,2}){
            cn[op]=0;
            val[op].clear();
        }
        ll sum=0;
        for(int i=1;i<=n;++i){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            ll mx=max({a[i][0],a[i][1],a[i][2]});
            if(mx==a[i][0]){
                ++cn[0];
                val[0].push_back(-max(a[i][1],a[i][2])+a[i][0]);
            }
            else if(mx==a[i][1]){
                ++cn[1];
                val[1].push_back(-max(a[i][0],a[i][2])+a[i][1]);
            }
            else{
                ++cn[2];
                val[2].push_back(-max(a[i][1],a[i][0])+a[i][2]);
            }
            sum+=mx;
        }
        int lm=n/2;
        if(cn[0]>lm){
            sort(val[0].begin(),val[0].end());
            int ncn=cn[0]-lm;
            for(int i=0;i<ncn;++i)sum-=val[0][i];
        }
        else if(cn[1]>lm){
            sort(val[1].begin(),val[1].end());
            int ncn=cn[1]-lm;
            for(int i=0;i<ncn;++i)sum-=val[1][i];
        }
        else{
            sort(val[2].begin(),val[2].end());
            int ncn=cn[2]-lm;
            for(int i=0;i<ncn;++i)sum-=val[2][i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}
/*
g++ -o club club.cpp -O2 -std=c++14 && time ./club
*/