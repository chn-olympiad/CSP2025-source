#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long p=0;
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(('0'<=s[i])&&(s[i]<='9')){
            a[p]=s[i];
            p++;
        }
    }
    sort(a,a+p);
    if(a[p-1]=='0'){
        cout<<0;
        return 0;
    }
    for(long long i=p;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
