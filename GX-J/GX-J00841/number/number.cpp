#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b=0,n;
    cin>>a;
    n=a.length();
    int num[n];
    for (int i=0;i<n;i++){
        if ((a[i]>='0')&&(a[i]<='9')){
            num[b]=a[i]-'0';
            b++;}}
    sort(num,num+b);
    for (int i=b-1;i>=0;i--){
      cout<<num[i];}
}
