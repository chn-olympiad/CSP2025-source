#include<bits/stdc++.h>
using namespace std;
string num;
long long n[1000001];
int hn=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>num;
    for(int i=0;i<num.length();i++){
        if(num[i]-'0'<=9 and num[i]-'0'>=0)
            n[hn++]=num[i]-'0';}
    int t,o=0;
    while(true){
        o=0;
        for(int i=0;i<hn-1;i++){
            if(n[i]<n[i+1])
                t=n[i],n[i]=n[i+1],n[i+1]=t;}
        for(int i=0;i<hn;i++){
            if(n[i]<n[i+1])
                o=1;}
        if(o==0)
        break;}
    for(int i=0;i<hn;i++){
        cout<<n[i];}
    return 0;
}
