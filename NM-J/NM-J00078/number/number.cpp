#include<bits/stdc++.h>
using namespace std;
int a[1000009];
bool cmp(int a, int b){
return a>b;
}
int main(){
freopen("number.in", "r", stdin);
freopen("number.out", "w", stdin);
string s,s1;
cin >> s;
for(int i=0; i<s.size(); i++){
    if(s[i]>='0' && s[i]<='9') s1+=s[i];
}
for(int i=0; i<s1.size(); i++){
    a[i]=s1[i]-'0';
}
sort(a, a+s1.size(), cmp);
for(int i=0; i<s1.size(); i++){
    cout <<a[i];
}
return 0;
}
