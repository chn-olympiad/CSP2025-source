#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z') s.erase(i,1),i--;
    }
    stable_sort(s.begin(),s.end(),greater<char>());
    while(s[0]=='0'&&s.size()>1) s.erase(0,1);
    cout<<s;
    return 0;
}
