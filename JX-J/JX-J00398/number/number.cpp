#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",std.in);
    freopen("number.out","w",std.out);
    string s,a;
    int c[1000005],w[1000005],e[1000005];
    long long f=0;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
            a=a+s[i];
        }
    }
    int b=a.length();
    for(int i=0;i<b;i++){
        c[i]=a[i]-'0';
    }
    for(int i=0;i<b;i++){
        e[i]=1;
    }
    if(b==1){
        f=c[0];
    }
    sort(c+1,c+b+1);
    for(int i=1;i<=b;i++){
        w[b-i]=c[i];
    }
    for(int i=0;i<b;i--){
       for(int j=i;j<b;j++){
            e[j]=e[j]*10;
       }
       f+=w[i]*e[i];
    }
    cout<<f;
    return 0;
}
