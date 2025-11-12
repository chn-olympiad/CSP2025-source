#include<bits/stdc++.h>
using namespace std;
int a[10],f=0;
string s;
int main(){
    freopen("number2.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(i==0&&f==0){
            cout<<0;
            break;
        }
        if(i!=0&&a[i])f=1;
        while(a[i]--)cout<<i;
    }
    return 0;
}
