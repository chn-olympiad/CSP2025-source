#include <bits/stdc++.h>
using namespace std;
bool c(int a,int b){
    if(a>=b){
        return a;
    }
    return 0;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
int a[100005]={};
int b=0;
for(int i=0;i<s.length();i++){
    if(s[i]>='0'&&s[i]<='9'){
        a[b]=s[i]-'0';
        b++;

    }}
sort(a,a+b,c);
for(int i=0;i<b;i++){
    cout<<a[i];
}

fclose(stdin);
fclose(stdout);
return 0;


}
