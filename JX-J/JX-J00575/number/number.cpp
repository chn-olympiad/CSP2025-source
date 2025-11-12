#include<bits/stdc++.h>
using namespace std;
int a[15],p=0;
string o;
int main(){
    cin>>o;
for(int i=0;i<o.size();i++){
    if(o[i]>=48&&o[i]<=57) a[o[i]-48]++;
}
for(int i=9;i>=0;i--){
    for(int j=1;j<=a[i];j++)
        printf("%d",i);
}
return 0;
}
