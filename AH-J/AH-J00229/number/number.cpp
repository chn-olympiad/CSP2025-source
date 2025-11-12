#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z'){
            s.erase(i,1);
            i--;
        }
    }
    sort(s.begin(),s.end());
    for(int i=s.size()-1;i>=0;i--){
        cout<<s[i];
    }
    return 0;
}
