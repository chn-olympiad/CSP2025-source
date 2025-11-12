#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long tj=0;
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]<s[i+1]){
            swap(s[i],s[i+1]);
        }
        if(s[i]>='0' and s[i]<='9'){
            cout<<s[i];
        }
    }
     return 0;
}
