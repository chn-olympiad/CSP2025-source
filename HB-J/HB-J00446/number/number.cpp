#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    priority_queue<int> q;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]>='0'&&s[i]<='9')
            q.push(s[i]-'0');
    bool flag=false;
    while(!q.empty()){
        if(q.top()!=0){
            flag=true;
            cout<<q.top();
        }else if(flag)
            cout<<q.top();
        q.pop();
    }
    if(!flag)cout<<0;
    return 0;
}
