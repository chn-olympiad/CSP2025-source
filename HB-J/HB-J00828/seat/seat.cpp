#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","i",s);
    freopen("seat.out","w",);
    int a,m,b,c,d,i,s;
    cin>>a>>b;
    cin>>c;m=c;
    for(i=1;i<a*b;i++){
        cin>>c;
        if(c>m) d++;
    }
    s=d%b;
    cout<<s;
    for(i=s;i>a;){

    }
    return 0;
}