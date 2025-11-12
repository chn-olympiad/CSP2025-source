#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(char x,char y){
    return x>y;
}
string s,t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(LL i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') t+=s[i];
    }
    sort(t.begin(),t.end(),cmp);
    cout<<t;
    return 0;
}
