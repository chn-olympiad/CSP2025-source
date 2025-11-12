#include<bits/stdc++.h>
using namespace std;
//"RP++RP++RP++RP++RP++"
string s;
vector<int>v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0),cout.tie(0);
    cin >> s;
    for(long long i=0;i<s.size();i++){
        long long x=s[i]-'0';
        if(0<=x && x<=9)v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(long long i=v.size()-1;i>=0;i--)cout << v[i];
    return 0;
}
//AC++AC++AC++AC++AC++
