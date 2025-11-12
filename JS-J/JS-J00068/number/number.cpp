#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<long long,vector<long long> >a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9')a.push(s[i]-'0');
    }
    while(!a.empty()){
        cout<<a.top();
        a.pop();
    }
    return 0;
}
