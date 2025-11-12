#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end(),greater<char>());
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'){
            s.erase(0,i);
            break;
        }
    }
    cout<<s;
    return 0;
}
