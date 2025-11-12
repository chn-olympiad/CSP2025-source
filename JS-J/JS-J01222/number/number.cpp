#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    priority_queue <char> pq;

    string s; cin >> s;
    for(int i = 0; i < s.size(); i++ ){
        if(s[i] >= '0' && s[i] <= '9') pq.push(s[i]);
    }


    if(pq.top() == '0') return cout << '0', 0;

    while(!pq.empty()){
        cout << pq.top();
        pq.pop();
    }

    return 0;

}
