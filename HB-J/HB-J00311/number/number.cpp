#include<bits/stdc++.h>
using namespace std;
bool c(int a,int b){
    if(a>b){
        return true;
    }
    else{
        return false;
    }
}
main(){
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    string a;
    int b[1000000],l,p=0;
    cin>>a;
    l=a.length();
    for(int i=0;i<l;i++){
            if(a[i]>='0' and a[i]<='9'){
                b[p]=a[i]-'0';
                p++;
            }
    }
    sort(b,b+p,c);
    for(int i=0;i<p;i++){
           cout<<b[i];
    }
    return 0;
}
