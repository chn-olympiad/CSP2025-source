#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
 int len,k;
 cin>>len>>k;
 int a[1005];
 bool f=1;
 for(int i=1;i<=len;i++){
    cin>>a[i];
    if(a[1]!=1) f=0;
 }
 if (f==1){
 cout<<len/k;
 }
 else {
    int sc=0;
    int temp=0;
    int i=1;
    while(i<len){
        temp=0;
    while(temp<k&&i<len){
        temp+=a[i];
        i++;
    }
    sc++;
    }
    cout<<sc;
 }
return 0;
}
