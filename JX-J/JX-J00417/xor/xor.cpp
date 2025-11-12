#include <bits/stdc++.h>
using namespace std;
int xorba(int a,int b){
    string a1="",b1="";
    int a2=a,b2=b;
    while(a2){
        a1=char(a2%2+'0')+a1;
        a2/=2;
    }
    while(b2){
        b1=char(b2%2+'0')+b1;
        b2/=2;
    }
    if(a1.size()<b1.size()){
        while(a1.size()!=b1.size())a1='0'+a1;
    }
    else{
        while(a1.size()!=b1.size())b1='0'+b1;
    }
    string c1="";int c2=0;
    for(int i=0;i<a1.size();i++){
        if(a1[i]==b1[i])c1=c1+'0';
        else c1=c1+'1';
    }
    for(int i=c1.size()-1,t=1;i>-1;i--,t*=2){
        c2+=(c1[i]-'0')*t;
    }
    return c2;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    int num[n+1]={},xo[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(i==1){
            xo[i]=num[i];
        }
        else{
            xo[i]=xorba(xo[i-1],num[i]);
        }
    }
    int ans=0;
    for(int i=1,j=2;i<=n;i++){
        int t=num[i];
        if(t==k){
            ans++;j++;
            continue;
        }
        while(xorba(xo[j],xo[i])!=k){
            j++;
        }
        ans++;i=j;
    }
    cout<<ans;
    return 0;
}
