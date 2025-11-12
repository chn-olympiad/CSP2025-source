#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000]{-1},jishu=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            char x=s[i];
            a[jishu]=x-'0';
            jishu++;
        }
    }
    sort(a,a+jishu);
    while(jishu--){
        cout<<a[jishu];
    }
    return 0;
}
