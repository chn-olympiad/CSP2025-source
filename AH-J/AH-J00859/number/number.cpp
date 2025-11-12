#include <bits/stdc++.h>
using namespace std;
priority_queue <int,vector<int> > q;
string s;
bool check(int x){
    return x>=0&&x<=9;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=int(s.size());i++){
        if(check(s[i]-'0')){
            q.push(s[i]-'0');
        }
    }
    while(!q.empty()){
        cout<<q.top();
        q.pop();
    }
    return 0;
}
