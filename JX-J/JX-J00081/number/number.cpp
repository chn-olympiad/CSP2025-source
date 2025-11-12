#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int cnt=0;
    priority_queue<int> q;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            int x=s[i]-48;
            q.push(x);
            if (x==0)
                cnt++;
        }
    }
    if (cnt==q.size()){
        cout<<0;
    }
    else{
        while (q.size()){
            int x=q.top();
            cout<<x;
            q.pop();
        }
    }
    return 0;
}
