#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000000+5],flag=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9') {
            a[flag]=s[i]-'0';
            flag++;
        }
    }
    flag-=1;
    sort(a+1,a+flag+1);
    for(int i=flag;i>=1;i--) cout<<a[i];
    return 0;
}
