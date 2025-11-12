#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> q;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int len = s.size();
    s = " " + s;
    for(int i = 1;i <= len;i++){
        if(isdigit(s[i])){
            q.push(s[i] - '0');
        }
    }
    while(!q.empty()){
        cout << q.top();
        q.pop();
    }
    return 0;
}
