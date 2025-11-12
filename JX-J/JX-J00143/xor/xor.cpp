#include<bits/stdc++.h>
using namespace std;
int a[200005]={};
int re=0,n,k,ii=0;
int xr(int a,int b){
    int res=0,ws=1;
    string a2,b2;
    a2=b2="";
    while(a!=0){
        a2+=a%2;
        a/=2;
    }
    while(b!=0){
        b2+=b%2;
        b/=2;
    }
    for(int i=0;i<min(a2.length(),b2.length());i--){
        if(a2[i]!=b2[i]) res+=ws;
        ws*=2;
    }
    if(a2.length()<=b2.length()){
        for(int i=a2.length();i<b2.length();i++){
            if(b2[i]==1) res+=ws;
            ws*=2;
        }
    }
    else{
        for(int i=b2.length();i<a2.length();i++){
            if(a2[i]==1) res+=ws;
            ws*=2;
        }
    }
    return res;
}
int js(int l,int r){
    int s=0;
    for(int i=l;i<=r;i++){
        s=xr(s,a[i]);
    }
    return s;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=ii+1;j<=i;j++){
            if(js(j,i)==k){
                ii=i;
                re++;
                break;
            }
        }
    }
    cout<<re;
    return 0;
}
