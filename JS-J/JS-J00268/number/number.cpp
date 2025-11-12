#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n;
string s;
priority_queue<int>q;
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') q.push(s[i]-'0');
    }
    while(q.size()){
        cout<<q.top();
        q.pop();
    }
    return 0;
}
