#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in",r,stdin);
    freopen("seat.out",w,stdout);
    char s[10000000];
    int a[10000000],x;
    cin>>s;
    for(int  i=0;i<10000000;i++){
        if(s[i]!='Z'){
            x++;
        }
    }
    for(int ii=0;ii<x;ii++){
        if(s[ii]-'1'>0 || s[ii]-'1'==0){
            a[ii]=int(s[ii]);
        }
    }
    sort(a,a+x);
    for(int j=x;j>=0;j--){
        cout<<a[j];
    }
    cout<<123;
    return 0;
}
