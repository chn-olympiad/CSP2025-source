#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
string s;
char a[1000005];
long long js=0,n;
bool px(char b,char c){
    return b>c;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<s.size();i++){
        if(!(s[i]>='A' && s[i]<='z')){
            a[js]=s[i];
            js++;
        }
    }
    sort(a,a+n,px);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
