#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll len;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    len=s.size();
    priority_queue<ll> pq;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            pq.push(s[i]-'0');
        }
    }
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
    return 0;
}
