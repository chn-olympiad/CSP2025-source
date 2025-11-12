#include<bits/stdc++.h>
using namespace std;
string s;
int a[9000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
cin>>s;
int cnt=0;
for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        a[cnt]=s[i]-48;
        cnt++;
    }
}
sort(a+0,a+0+cnt);
for(int i=cnt-1;i>=0;i--){
    cout<<a[i];
}
return 0;
}
