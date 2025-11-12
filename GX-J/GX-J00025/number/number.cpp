#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a[1000010],c=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        s1+=s[i];
    }
}
for(int i=0;i<s1.size();i++){
    a[c]=(int )s1[i]-48;
    c++;
}
sort(a+1,a+c+1,cmp);
for(int i=1;i<c;i++){
    cout<<a[i];
}
return 0;
}
