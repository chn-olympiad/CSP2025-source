#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string num;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')num+=s[i];
    }
    sort(num.begin(),num.end());
    for(ll i=num.size()-1;i>=0;i--)printf("%c",num[i]);
    return 0;
}
/*
PLEASE AC!!!!!!!!!!
*/
