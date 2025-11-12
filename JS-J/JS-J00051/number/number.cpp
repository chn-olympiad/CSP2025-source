#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int,vector<int>,less<int>> q;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]<='9'&&s[i]>='0'){
            q.push(s[i]-'0');
        }
    }
    while(q.size()){
        cout<<q.top();
        q.pop();
    }
    return 0;
}
