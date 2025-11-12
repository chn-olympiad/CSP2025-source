#include <bits/stdc++.h>
using namespace std;
string s;
long long a[11];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();++i){
        if('0'<=s[i]&&s[i]<='9'){
            ++a[s[i]-48];
        }
    }
    for(int i=9;i>=0;--i){
        if(a[i]==0){
            continue;
        }
        for(long long j=0;j<a[i];++j){
            printf("%d",i);
        }
    }
    return 0;
}
