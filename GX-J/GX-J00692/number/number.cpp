#include <bits/stdc++.h>
using namespace std;

string s;
char a[1000005];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int x=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[x]=s[i];
            x++;
        }
    }
    sort(a,a+x,greater<char>());
    for(int i=0;i<x;i++){
        cout<<a[i];
    }
    return 0;
}
