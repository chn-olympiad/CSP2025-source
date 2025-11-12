#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
char a[1000000];char b[1000000];char c;int d=0;
gets(a);
for(int i=0;i<=strlen(a);i++){
if(a[i]<='9'&&a[i]>='0'){
b[d]=a[i];d++;
}
}
for(int i=0;i<strlen(b);i++){
for(int u=0;u<strlen(b)-1;u++){
if(b[u]<b[u+1]){
c=b[u];
b[u]=b[u+1];
b[u+1]=c;
}
}
}
for(int i=0;i<=strlen(b);i++){
cout<<b[i];
}
fclose(stdin);fclose(stdout);
return 0;
} 
