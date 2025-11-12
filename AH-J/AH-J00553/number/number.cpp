#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e6+10;
priority_queue<LL> pq;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(LL i=0;i<s.size();i++)
        if(isdigit(s[i]))
            pq.push(s[i]-'0');
    while(!pq.empty()){
        printf("%lld",pq.top());
        pq.pop();
    }
    return 0;
}
