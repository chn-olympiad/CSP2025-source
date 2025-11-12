#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
string s;
int a[N],t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) if(isdigit(s[i])) a[++t]=(s[i]-'0');
    sort(a+1,a+t+1,greater<int>());
    for(int i=1;i<=t;i++) cout<<a[i];
}
//expected: 100pts
