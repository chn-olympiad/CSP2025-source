#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> q;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); ++i){
        if(s[i]>'0' && s[i]<='9'){
            q.push(s[i]-'0');
        }
    }
    while(!q.empty()){
        cout<<q.top();
        q.pop();
    }
    return 0;
}
