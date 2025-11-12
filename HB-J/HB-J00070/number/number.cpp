#include<bits/stdc++.h>
using namespace std;
string s,num;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<(int)s.size();++i){
        if(48<=s[i]&&s[i]<=57){
            num+=s[i];
        }
    }
    sort(num.begin(),num.end(),cmp);
    cout<<num<<"\n";
    return 0;
}
