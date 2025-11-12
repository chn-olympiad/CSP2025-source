#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define pii pair<int,int>
#define st(s) sort(s.begin(),s.end())
#define pb(n) push_back(n)
#define rv(s) reverse(s.begin(),s.end())
#define ins(n) insert(n)
#define vt vector
#define endl "\n"
int sz[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9'){
            sz[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<sz[i];j++){
            cout<<i;
        }
    }
    return 0;
}
//100 points
