#include<bits/stdc++.h>
using namespace std;
int a[100100],b,c=0;
bool cmp(int a,int b){
return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        b=s[i]-'0';
        a[c]=b;
        c++;
    }
}
sort(a,a+c,cmp);
for(int i=0;i<c;i++){
    cout<<a[i];
}
return 0;
}
