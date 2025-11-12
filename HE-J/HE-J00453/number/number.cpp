#include<bits/stdc++.h>
using namespace std;
bool cmd (int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string op="",s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')op+=s[i];
    }
    sort(op.begin(),op.end(),cmd);
    cout<<op<<"\n";
    return 0;
}
