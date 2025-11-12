#include <bits/stdc++.h>
using namespace std;
char d[1000002];
int l[1000002];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a=0;
    string s;
    cin>>s;
    for(int i=0;i<sizeof(s);i++){
        if(isdigit(s[i])){
            d[a]=s[i];
            a++;
        }
    }
    for(int j=0;j<a;j++){
        l[j]=(int)d[j]-48;
    }
    sort(l,l+a);
    for(int i=a-1;i>=0;i--){
        cout<<l[i];
    }
    return 0;
}
