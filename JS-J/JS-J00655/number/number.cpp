#include<bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue<char> pq;

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            pq.push(s[i]);
    }
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }

    return 0;
}

