#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<int> pq;
int main(){
    freopen( "number.in" , "r", stdin);
    freopen( "number.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int s_size = s.size();
    for(int i = 0; i < s_size ; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            int tmp=(s[i]*1)-'0';
            pq.push(tmp);
        }
    }
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
    return 0;
}
