#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<=s[i+1]){
            swap(s[i],s[i+1]);
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cout<<s[i];
        }
    }

    return 0;
}
