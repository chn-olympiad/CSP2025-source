#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000005]={},p=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
       if((int)(s[i])>=48&&(int)(s[i])<=57){

            a[p]=s[i]-'0';
            p++;
       }

    }
    sort(a,a+p);
    for(int i=p-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
