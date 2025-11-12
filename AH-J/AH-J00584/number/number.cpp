#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main(){
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
string s;
getline(cin,s);
int len=s.size();
int a[len+5]={},x=0;
for(int i=0;i<len;i++){
    if(s[i]>='0'&&s[i]<='9'){
        a[x]=s[i]-'0';
        x++;
    }
}
sort(a,a+x+1,cmp);
for(int i=x;i>0;i--){
    cout<<a[i];
}
return 0;
}
