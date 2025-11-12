#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str;
priority_queue<int>q;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
            q.push((int)(str[i]-'0'));
        }
    }
    while(!q.empty()){
        printf("%d",q.top());
        q.pop();
    }
    return 0;
}
//rp++
