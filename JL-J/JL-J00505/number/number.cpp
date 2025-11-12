#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string k;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            k+=s[i];
        }
    }
    sort(k.begin(),k.end(),greater<char>());
    cout<<k<<endl;
    return 0;
}
