#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,c;
    int a[100]={0},num=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            a[s[i]-'0']++;
            if(s[i]>'0'){
                num++;
            }
        }
    }
    int b=10;
    while(b--){
        for(int i=1;i<=a[b];i++){
            c+=b+'0';
        }
    }
    if(num==0){
        cout<<0;
    }else{
        cout<<c;
    }
    return 0;
}
