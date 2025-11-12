#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size(),cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=int(s[i]-'0');
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}