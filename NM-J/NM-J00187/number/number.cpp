#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    for(int i=1;i<=s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            cout<<s[i];
        }
    }
    return 0;
}
