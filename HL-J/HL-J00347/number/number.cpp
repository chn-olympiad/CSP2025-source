#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    vector<int>num;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int cur=s[i]^48;
            num.push_back(cur);
        }
    }
    sort(num.begin(),num.end(),cmp);
    for(auto a:num){
        cout<<a;
    }
    return 0;
}
