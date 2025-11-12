#include <bits/stdc++.h>
using namespace std;
int ns[100010],tot=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++){
        if (s[i]>='0'||s[i]<='9') ns[tot++]=s[i]-'0';}
    sort(ns,ns+tot);
    for (int i=0;i<tot;i++) cout << ns[i];
    return 0;}
