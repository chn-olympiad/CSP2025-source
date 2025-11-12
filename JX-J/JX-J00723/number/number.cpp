#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int num[1000001];
    int a=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48&&s[i]<=58){
            a++;
            num[a]=s[i]-'0';
        }
    }
    for(int i=1;i<a;i++){
        for(int j=1;j<=a-i;j++){
            if(num[i]<num[i+j])swap(num[i],num[i+j]);
        }
    }
    for(int i=1;i<=a;i++){
        cout<<num[i];
    }
    return 0;
}
