#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> num(15);
    for(int i=0;i<(int)s.size();++i){
        int t=(int)(s[i]-'0');
        num[t]+=1;
    }
    for(int i=9;i>=0;--i){
        for(int j=0;j<num[i];++j){
            cout<<i;
        }
    }
    return 0;
}