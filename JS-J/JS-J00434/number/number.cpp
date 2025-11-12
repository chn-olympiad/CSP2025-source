#include <bits/stdc++.h>
using namespace std;

string s;
priority_queue<int> pq;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(auto ch:s){
        if(isdigit(ch)){
            pq.push(ch-'0');
        }
    }
    while(!pq.empty()){
        cout << pq.top();
        pq.pop();
    }
    cout << endl;
    return 0;
}