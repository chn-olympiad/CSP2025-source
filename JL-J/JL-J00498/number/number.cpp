//70
#include<bits/stdc++.h>
using namespace std;
string s;
string t;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            t=t+s[i];
        }
    }

    sort(t.begin(),t.end(),cmp);
    cout<<t;
    return 0;
}
