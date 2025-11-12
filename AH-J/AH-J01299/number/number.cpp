#include<bits/stdc++.h>
using namespace std;
string s;
long long n[1000000],c=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            n[c]=s[i]-'0';
            c++;
        }
    }
    sort(n,n+c);
    for(int i=c-1;i>=0;i--){
        cout<<n[i];
    }
    return 0;
}


