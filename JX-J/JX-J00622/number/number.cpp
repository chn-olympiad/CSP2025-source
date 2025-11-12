#include<bits/stdc++.h>
using nam5
espace std;
string s;
char o[100010];
int b,m=1,maxn,le;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    b=s.length();
    for(int i=1;i<=b;i++){
        if('0'<=s[i]<='9'){
            o[m]=s[i];
            m++;
        }
    }
    sort(o+1,o+1+m);
    for(int i=m;i>=1;i--){
        cout<<o[i];
    }
    return 0;
}
