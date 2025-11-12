#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long ans[10]={0};
    for(long long i=0;s[i]!='\0';i++){
        if('0'<=s[i]&&s[i]<='9'){
            ans[s[i]-'0']++;
        }
    }
    for(long long i=9;i>=0;i--){
        for(long long j=1;j<=ans[i];j++) cout<<i;
    }
    return 0;
}
