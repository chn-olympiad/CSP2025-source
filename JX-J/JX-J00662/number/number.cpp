#include<bits/stdc++.h>
using namespace std;
int r[1009],e=1;

int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
getline(cin,s);
for(int i=0;i<s.size();i++){
char c=s[i];
int a=c-'0';
if(a>=0&&a<=9){
r[e]=a;
e++;
}
}
sort(r+1,r+e+1);
for(int i=e;i>1;i--){
cout<<r[i];
}
if(e==1) cout<<0;
return 0;
fclose(stdin);
fclose(stdout);
}
