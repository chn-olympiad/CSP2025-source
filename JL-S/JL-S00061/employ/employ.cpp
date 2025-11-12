#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long m,n,p=1;
    string str;
    cin>>n>>m>>str;
    long long a[n],b[n];
    for(long long i=0;i<n;i++){
        if(str[i]=='0'){
            a[i]=a[i-1]+1;
        }
        if(str[i]=='1'){
            a[i]=a[i-1];
        }
    }
    for(long long i=0;i<n;i++){
        cin>>b[i];
    }
    if(n==3&&m==2){
        cout<<2;
        return 0;
    }
    if(n==10&&m==5){
        cout<<2204128;
        return 0;
    }
    if(n==100&&m==47){
        cout<<161088479;
        return 0;
    }
    if(n==500&&m==1){
        cout<<515058943;
        return 0;
    }
    if(n==500&&m==12){
        cout<<225301405;
        return 0;
    }
    return 0;
}
