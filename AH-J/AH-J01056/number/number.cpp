#include "bits/stdc++.h"
#define int long long
using namespace std;
priority_queue<int> q;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            int t=s[i]-'0';
            q.push(t);
        }
    }
    while(!q.empty()){
        cout<<q.top();
        q.pop();
    }
    return 0;
}
