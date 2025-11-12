#include<bits/stdc++.h>
using namespace std;
int a[1000001];
string b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int csp=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[csp]=s[i];
            csp++;
        }
    }
    for(int i=0;i<csp;i++){
        a[b[i]-'0']++;
    }
    int d=a[9],e=a[8],f=a[7],g=a[6],h=a[5],j=a[4],k=a[3],m=a[2],n=a[1],ccf=a[0];
    for(int i=1;i<=d;i++) cout<<"9";
    for(int i=1;i<=e;i++) cout<<"8";
    for(int i=1;i<=f;i++) cout<<"7";
    for(int i=1;i<=g;i++) cout<<"6";
    for(int i=1;i<=h;i++) cout<<"5";
    for(int i=1;i<=j;i++) cout<<"4";
    for(int i=1;i<=k;i++) cout<<"3";
    for(int i=1;i<=m;i++) cout<<"2";
    for(int i=1;i<=n;i++) cout<<"1";
    for(int i=1;i<=ccf;i++) cout<<"0";
    return 0;
}
