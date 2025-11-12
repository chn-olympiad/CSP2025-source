#include<bits/stdc++.h>
using namespace std;
string s;
int t[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) t[s[i]-48]++;
    }
    for(int i=9;i>=0;i--) while(t[i]--) putchar(i+48);
    putchar('\n');
    return 0;
}
