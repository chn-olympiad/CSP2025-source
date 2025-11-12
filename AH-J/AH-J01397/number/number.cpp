#include<bits/stdc++.h>
using namespace std;
string s,t;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t+=s[i];
        }
    }
    sort(t.begin(),t.end(),cmp);
    if(t[0]==0){
        cout<<0;
         return 0;
    }else{
        cout<<t;
    }
    return 0;
}
