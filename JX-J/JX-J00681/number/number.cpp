#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
string s;
vector<int> g;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.length();
    for (int i=0;i<l;i++) {
        if (s[i]>='0'&&s[i]<='9') g.push_back(s[i]-'0'); 
    }
    sort(g.begin(),g.end(),greater<int>());
    for (int i=0;i<g.size();i++) cout<<g[i];
    return 0;
}