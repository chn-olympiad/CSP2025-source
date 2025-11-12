#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s="";
    //long long a=0;
    cin>>s;
    map<int,int> m={};
    for(int i=0;i<=s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            int t=s[i]-'0';
            //cout<<t<<" ";
            m[t]++;
        }
    }
    //cout<<"\n";
    //for(int i=0;i<=9;i++){
        //cout<<m[i]<<" ";
    //}
    for(int i=9;i>=0;i--){
        while(m[i]!=0){
            //a=a*10+i;
            cout<<i;
            m[i]--;
        }
    }
    //cout<<"\n";
    //printf("%lld",a);
    return 0;

}
