#include<bits/stdc++.h>
using namespace std;
long long a[1000002],aaa=1;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9){
            a[aaa]=s[i]-'0';
            aaa=aaa+1;
        }
    }
    sort(a+1,a+1+aaa);
    for(int i=aaa;i>=2;i--){
            cout<<a[i];
        }
        return 0;
    }

