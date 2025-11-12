#include <bits/stdc++.h>
using namespace std;

long long a[10]={0};
string s;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(long long i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        a[s[i]-'0']++;
    }
}
for(int i=9;i>=0;i--){
    for(int i2=0;i2<a[i];i2++){
        cout<<i;
    }
}

return 0;
}
