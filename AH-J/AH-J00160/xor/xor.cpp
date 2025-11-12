#include<bits/stdc++.h>
using namespace std;
long long a[500010];
string erjz(int n){
    int l=0,x[500010];
    while(n!=0){
        a[l]=n%2;
        n/=2;
        l++;
    }
    string s="";
    for(int i=l-1;i>=0;i--){
        s+=(a[i]+'0');
    }
    return s;
}
string yl(string s1,string s2){
    string d="";
    int mx=max(s1.size(),s2.size());
    if(s1.size()>s2.size()){
        for(int i=1;i<=mx-s2.size();i++){
            s2='0'+s2;
        }
    }else{
        for(int i=1;i<=mx-s1.size();i++){
            s1='0'+s1;
        }
    }
    for(int i=1;i<=mx;i++){
        if(s1[i]!=s2[i]){
            d[i]+='1';
        }
    }
    return d;
}
int sjz(string x){
    int h=0,d=0;
    for(int i=x.size();i>=1;i--){
        h+=(x[i]-48)*pow(2,d);
        d++;
    }
    return h;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long x,y,i,w=0,cnt=0;
    cin>>x>>y;
    for(i=1;i<=x;i++){
        cin>>a[i];
    }
    for(i=1;i<=x;i++){
        for(int j=1;j<=i;j++){
            w=sjz(yl(erjz(a[i]),erjz(a[i+1])));
        }
        if(w==y){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
