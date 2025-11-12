#include<bits/stdc++.h>
using namespace std;
string s;
vector<long long>v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(long long i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <='9'){
           v.push_back(int(s[i]-48));
        }
    }sort(v.begin(),v.end());
    for(long long i = v.size()-1; i >= 0; i--){
        cout << v[i];
    }return 0;
}
