#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(vector<ll> a,vector<ll> b){
    return a[0] > b[0];
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    vector<ll> m;
    vector<vector<ll>> s;
    int o;
    cin >> o;
    m.push_back(o);
    if(m[0] == k){
        s.push_back({0,0});
    }
    int z;
    for(int i = 1;i < n;i++){
        cin >> o;
        m.push_back(m[i-1]^o);
        if(o == k){
            s.push_back({i,i});
        }else if(m[i] == k){
            s.push_back({0,i});
            z = i;
        }else{
        auto c = find(m.begin(),m.end(),k^m[i]);
        if(c != m.end()){
            s.push_back({c-m.begin()+1,i});
        }
        }
    }
    sort(s.begin(),s.end(),cmp);
    cout << s.size();
    return 0;
}
