#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1;
    cin>>s;
    for(LL i=0;i<s.size();i++){
        if(isdigit(s[i])){
            s1+=s[i];
        }
    }
    sort(s1.begin(),s1.end());
    reverse(s1.begin(),s1.end());
    cout<<s1;
    return 0;
}
