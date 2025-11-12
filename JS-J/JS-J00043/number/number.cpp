#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int num=0,num1=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            num=num+1;
        }
    }
    sort(a,a+s.length());
    for(int i=s.length()-1;i>=0;i--){
        if(num1==num){
            break;
        }
        cout<<a[i];
        num1++;
    }
    return 0;
}
