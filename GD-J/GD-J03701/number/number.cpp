#include<bits/stdc++.h>
using namespace std;
char a[1000000];int n=0;int b[1000000];int c[1000000];int main(){
    freopen("munber.in","r",stdin);
    freopen("munber.out","w",stdout);
    cin>>a;int n;
    for(;n<=1000000;n++){
        if(a[n]<48||a[n]>122){break;}
    }//cout<<n;
    int d=1;
    for(int i=1;i<n+1;i++){
        if(a[i]>=48&&a[i]<=57){b[d]=a[i];d++;}
    }//cout<<b[3];//cout<<d;
    //for(int i=1;i<=d;i++){c[i]=a[b[i]];}
    sort(b+1,b+d+1);
    for(int i=d;i>0;i--){
        c[i]=(char)b[i];}
    for(int i=d;i>=0;i--){
    cout<<(char)c[i]<<" ";}
    return 0;
}
