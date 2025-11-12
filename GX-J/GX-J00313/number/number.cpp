#include<iostream>
#include<cstring>
using namespace std;
int ans,a[2000001],k,len,t[201],c;
char s[2000001];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
len=strlen(s);
for(int i=0;i<=len;i++){
    if(48<=int(s[i]) && int(s[i])<=57){
        a[k]=s[i]-'0';
        k+=1;
    }
}
for(int i=0;i<k;i++){
    c=a[i];
    t[c]++;
}
c=0;
for(int i=10;i>=0;i--){
    while(t[i]!=0){
        a[c]=i;
        t[i]--;
        c++;
    }
}
for(int i=0;i<k;i++) cout<<a[i];
fclose(stdin);
fclose(stdout);
return 0;
}
