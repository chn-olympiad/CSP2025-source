#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int> > q;
int main(){
    freopen("number.in","r",stdin);//666 cha dian bu hui xie
    freopen("number.out","w",stdout);
    string s;
    char c;
    cin>>s;
    for(int i=0;i<s.length();i++){
        c=s[i];
        if('0'<=c&&c<='9'){
            q.push(c-'0');
        }
    }
    string ans;
    while(!q.empty()){
        c=q.top();
        q.pop();
        ans+=(c+'0');
    }
    cout<<ans;
	return 0;
}
