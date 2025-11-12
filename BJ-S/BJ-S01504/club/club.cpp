#include<bits/stdc++.h>
using namespace std;using LL=int64_t;using LD=long double;
#define f(i,a,b) for(int i=(a),E##i=(b);i<=E##i;++i)
#define fr(i,a,b) for(int i=(a),E##i=(b);i>=E##i;--i)
#define fu(i,a,b) for(int i=(a),E##i=(b);i<E##i;++i)
#define endl '\n'
auto freo(string s){
    string in=s+".in";
    string out=s+".out";
    return make_pair(
        freopen(in.c_str(),"r",stdin),
        freopen(out.c_str(),"w",stdout)
    );
}
int solve(){
    int n;cin>>n;
    vector<array<int,3>>a(n);
    array<int,3>cnt{};
    int ans=0;
    for(auto &v:a){
        for(int &x:v)cin>>x;
        int j=max_element(v.begin(),v.end())-v.begin();
        ++cnt[j],ans+=v[j];
    }
    int kj=max_element(cnt.begin(),cnt.end())-cnt.begin();
    int k=cnt[kj],lk=n/2;
    if(k<=lk)return ans;
    k-=lk;
    vector<int>b;
    for(auto v:a){
        int j=max_element(v.begin(),v.end())-v.begin();
        if(j==kj){
            sort(v.begin(),v.end());
            b.emplace_back(v[2]-v[1]);
        }
    }
    // assert(k<=int(b.size()));
    sort(b.begin(),b.end());
    fu(i,0,k)ans-=b[i];
    return ans;
}
int main(){
    freo("club");
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)cout<<solve()<<endl;
    return 0;
}
//pass sample:14:42