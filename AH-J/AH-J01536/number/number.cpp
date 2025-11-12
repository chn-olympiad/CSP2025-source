#include<bits/stdc++.h>
using namespace std;
string ss;
vector<short> s;
bool cmp(short a,short b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>ss;
    for(int i=0;i<ss.size();i++){
        if(ss[i]>='0' && ss[i]<='9'){
            s.push_back(ss[i]-'0');
        }
    }
    sort(s.begin(),s.end(),cmp);
    if(s[0]==0){
        cout<<0<<endl;
        return 0;
    }
    for(auto p:s){
        cout<<p;
    }
    cout<<endl;
    return 0;
}
