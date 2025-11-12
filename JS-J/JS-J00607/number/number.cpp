#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            pq.push(s[i]-'0');
        }
    }
    len=pq.size();
    for(int i=0;i<len;i++){
        cout<<pq.top();
        pq.pop();
    }
    return 0;
}
