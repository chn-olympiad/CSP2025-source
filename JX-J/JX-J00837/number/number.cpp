#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],k;
int zd(){
    int bg=-1,n=-1;
    for(int j=1;j<=k;j++){
        if(a[j]>bg){
            bg=a[j];
            n=j;
        }
    }
    a[n]=0;
    return bg;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if((int)s[i]>=48 && (int)s[i]<=57){
            k+=1;
            a[k]=(int)s[i]-48;
        }
    }
    int num=0;
    for(int i=1;i<=k;i++) num+=a[i];
    if(num==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=k;i++) cout<<zd();
    return 0;
}
