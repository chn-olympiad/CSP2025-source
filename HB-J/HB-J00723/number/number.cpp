#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            vec.push_back(s[i]-'0');
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i:vec){
        cout<<i;
    }
    return 0;
}
//HB-J00723 shizouyu 04-03 22025.11.01  ⨌
