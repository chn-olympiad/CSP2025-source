#include<bits/stdc++.h>
using namespace std;
long long a[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    cin>>s;
    for(long long i=0;i<s.length();i++){
        if (s[i]>='0' && s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(long long i=9;i>=0;i--){
        while(a[i]>0){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}

