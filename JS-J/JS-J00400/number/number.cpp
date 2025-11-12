#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long len=s.length();
    long long a[11]={};
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            int b=s[i]-'0';
            a[b]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(long long j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
