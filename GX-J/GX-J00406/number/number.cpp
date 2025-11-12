#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,b;
    cin>>a;
    for(int z=0;z<a.length();z++){
        if(a[z]=='0'){
            b+=a[z];
        }
        if(a[z]=='1'){
            b+=a[z];
        }
        if(a[z]=='2'){
            b+=a[z];
        }
        if(a[z]=='3'){
            b+=a[z];
        }
        if(a[z]=='4'){
            b+=a[z];
        }
        if(a[z]=='5'){
           b+=a[z];
        }
        if(a[z]=='6'){
            b+=a[z];
        }
        if(a[z]=='7'){
            b+=a[z];
        }
        if(a[z]=='8'){
            b+=a[z];
        }
        if(a[z]=='9'){
            b+=a[z];
        }
        }
    for(int i=0;i<b.length();i++){
        for(int j=0;j<b.length();j++){
        if(b[i]>b[j]){
            int c;
            c=b[i];
            b[i]=b[j];
            b[j]=c;
        }
    }
    }
    cout<<b;
    return 0;
}
