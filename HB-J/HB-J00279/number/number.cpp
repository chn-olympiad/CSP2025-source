#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long len=0;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9) a[++len]=s[i]-'0';
    }
    sort(a+1,a+1+len);
    for(int i=len;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
