#include<bits/stdc++.h>
using namespace std;
int n,m[1500000],a,b,c,d;
int main(){
    char b1='0',c1='9',d1;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    b=b1;
    c=c1;
    string s;
    cin>>s;
    n=s.size();
   for(int i=0;i<n;i++){
        a=s[i];
        if(a>=b&&a<=c){
            d1=s[i];
            d=d1;
            m[i]=d-b;
        }else{
            m[i]=10;
        }
    }
    sort(m,m+n);
    for(int i=n-1;i>=0;i--){
        if(m[i]<10)
            cout<<m[i];
    }
    return 0;
}
