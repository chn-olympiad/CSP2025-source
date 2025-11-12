#include<bits/stdc++.h>
using namespace std;
void solve(){
    char c;
    priority_queue<long long> q;
    while(cin >> c){
        if(c>='0' and c<='9')
            if(c=='9') 
                cout << c;
            else q.push((int)(c-'0'));
    }
    
    while(!q.empty()){
        int up=q.top();
        printf("%d",up);
        q.pop();
    }
    // cout << (int)'1';
    return;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    solve();
    return 0;
}
