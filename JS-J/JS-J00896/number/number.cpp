#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> p;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        int a=s[i]-'0';
        if(a<10&&a>=0){
            p.push(a);
        }
    }
    if(p.top()==0){
        cout<<"0";
        return 0;
    }
    else{
        while(!p.empty()){
            cout<<p.top();
            p.pop();
        }
    }
}
