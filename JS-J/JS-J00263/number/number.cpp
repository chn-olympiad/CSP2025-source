#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int cnt;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            q.push(int(s[i])-48);
        }
    }
    for(int i=1;i<=cnt;i++){
        cout<<q.top();
        q.pop();
    }
    return 0;
}

