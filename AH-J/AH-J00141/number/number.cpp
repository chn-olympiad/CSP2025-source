#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,anss;
bool cmp(const char &x,const char &y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end(),cmp);
    for(LL i=0;i<s.size();i++){
        if(isdigit(s[i])){
            anss+=s[i];
        }
    }
    cout<<anss;
    return 0;
}
