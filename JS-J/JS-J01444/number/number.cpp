#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,tmp;
string s;
vector<ll> a;
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>s;
    s = " " + s;
    n = s.size();
    for(int i = 1;i <= n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            tmp = s[i] - '0';
            a.push_back(tmp);
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i =0;i < a.size();i++){
        cout<<a[i];
    }
    cout<<'\n';
    return 0;
}
