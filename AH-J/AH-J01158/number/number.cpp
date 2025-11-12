#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,as;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
         if(isdigit(s[i])) as+=s[i];
    }
    sort(as.begin(),as.end());
    reverse(as.begin(),as.end());
    cout<<as;
    return 0;
}
