#include<bits/stdc++.h>
using namespace std;
string a;
int i,c[50];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(i=0;i<a.length();i++){
        if(a[i]=='0') c[0]++;
        if(a[i]=='1') c[1]++;
        if(a[i]=='2') c[2]++;
        if(a[i]=='3') c[3]++;
        if(a[i]=='4') c[4]++;
        if(a[i]=='5') c[5]++;
        if(a[i]=='6') c[6]++;
        if(a[i]=='7') c[7]++;
        if(a[i]=='8') c[8]++;
        if(a[i]=='9') c[9]++;
    }
    for(i=1;i<=c[9];i++){
        cout<<9;
    }
    for(i=1;i<=c[8];i++){
        cout<<8;
    }
    for(i=1;i<=c[7];i++){
        cout<<7;
    }
    for(i=1;i<=c[6];i++){
        cout<<6;
    }
    for(i=1;i<=c[5];i++){
        cout<<5;
    }
    for(i=1;i<=c[4];i++){
        cout<<4;
    }
    for(i=1;i<=c[3];i++){
        cout<<3;
    }
    for(i=1;i<=c[2];i++){
        cout<<2;
    }
    for(i=1;i<=c[1];i++){
        cout<<1;
    }
    for(i=1;i<=c[0];i++){
        cout<<0;
    }
    return 0;
}
