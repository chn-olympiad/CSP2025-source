#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    getline(cin,str);
    int Size=str.size();
    for(int i=0;i<Size;i++){
        if(str[i]>='0'&&str[i]<='9'){
            pq.push(str[i]-'0');
        }
    }
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
    return 0;
}
