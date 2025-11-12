#include <bits/stdc++.h>
#include <algorithm>
#define ll longlong 
using namespace std;

int factorial(int n){
    return n*factorial(n-1);
}
int main(){
        freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int a,b;
scanf("%d",&a);
scanf("%d",&b);
string c;
scanf("%s",c);
int flag,asdffdsa;
flag=0;
asdffdsa=0;
for(int i=1;i==a;i++){
    scanf("%d",asdffdsa);
    if(asdffdsa>=a){
        flag+=1;
    }
}
printf("%d",factorial(flag));
fclose(stdin);
fclose(stdout);
return 0;
}