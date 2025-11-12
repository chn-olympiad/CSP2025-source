#include<bits/stdc++.h>
using namespace std;
int su[10],x;
string s,an;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            x=s[i]-'0';
            su[x]+=1;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<su[i];j++){
            an+=i+'0';
        }
    }
    int m=0;
    for(int i=1;i<=9;i++){
        if(su[i]>0){
            m++;
            break;
        }
    }
    if(m==0){
        cout<<0;
    }else{
        cout<<an;
    }
    return 0;
}
