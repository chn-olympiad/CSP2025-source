#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen(number.in,"r",std.in);
    freopen(number.out,"w",std.out);
    string s;
    cin>>s;
    int a1[1000005];
    int o=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a1[o++]=s[i]-'0';
        }
    }
    sort(a1,a1+o,cmp);
    for(int i=0;i<o;i++){
        cout<<a1[i];
    }
    return 0;
}
