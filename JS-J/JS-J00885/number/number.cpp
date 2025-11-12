#include <bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0'+1]++;
        }
    }
    for(int i=10;i>=1;i--){
        while(a[i]--){
            std::cout<<i-1;
        }
    }
}
