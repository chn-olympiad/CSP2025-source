#include<bits/stdc++.h>
using namespace std;
string num,s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)if(s[i]>='0'&&s[i]<='9')num+=s[i];
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    if(count(num.begin(),num.end(),'0')==num.length())cout<<0;
    else cout<<num;
    return 0;
}
