#include <bits/stdc++.h>
using namespace std;
priority_queue<int> num;
string s;
void sovle(){
    cin>>s;
    int len = s.size();
    for(int i=0;i<len;++i){
        if(s[i]>='0'&&s[i]<='9'){
            int k = s[i] - '0';
            num.push(k);
        }
    }
    while(!num.empty()){
        cout<<num.top();
        num.pop();
    }
    return;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 1;
    while(N--) sovle();
    return 0;
}
