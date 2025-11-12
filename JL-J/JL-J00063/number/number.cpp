#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    priority_queue<int>asd;
    string h;
    cin>>h;
    for(int i=0;i<h.size();i++){
        if(h[i]>='0'&&h[i]<='9'){
            asd.push(h[i]-'0');
        }
    }while(!asd.empty()){
        cout<<asd.top();
        asd.pop();
    }
    return 0;
}
