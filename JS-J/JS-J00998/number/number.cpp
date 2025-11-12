#include <bits/stdc++.h>//cccf i love u!!!!!!!!!!!!!
using namespace std;
priority_queue<int> q;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9') q.push(s[i] - '0');
    }
    if(q.top() == 0 && q.size() > 1 ){
        cout << q.top();
        return 0;
    }
    while(!q.empty()){
        int x = q.top();
        cout << x;
        q.pop();
    }
    return 0;
}