#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000010],cnt;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
cnt=0;
for(int i=0;i<s.length();i++){
    if(s[i]>='0'&&s[i]<='9'){
        num[cnt]=s[i]-'0';
        cnt++;
    }
}
sort(num,num+cnt);
for(int i=cnt-1;i>=0;i--){
    cout<<num[i];
}
return 0;
}
