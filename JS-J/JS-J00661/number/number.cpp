#include <bits/stdc++.h>
using namespace std;
string s,t;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            t+=s[i];
    }
    sort(t.begin(),t.end(),cmp);
    cout<<t;
    return 0;
}
