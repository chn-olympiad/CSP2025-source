#include<bits/stdc++.h>
using namespace std;
int n,s,a[1000001];
string c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    for(int i=0;i<c.size();i++){
        if(c[i]=='0'){
            a[i]=0;
            s++;
        }
        if(c[i]=='1'){
            a[i]=1;
            s++;
        }
        if(c[i]=='2'){
            a[i]=2;
            s++;
        }
        if(c[i]=='3'){
            a[i]=3;
            s++;
        }
        if(c[i]=='4'){
            a[i]=4;
            s++;
        }
        if(c[i]=='5'){
            a[i]=5;
            s++;
        }
        if(c[i]=='6'){
            a[i]=6;
            s++;
        }
        if(c[i]=='7'){
            a[i]=7;
            s++;
        }
        if(c[i]=='8'){
            a[i]=8;
            s++;
        }
        if(c[i]=='9'){
            a[i]=9;
            s++;
        }
        n++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]<a[i]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int j=0;j<s;j++){
        cout<<a[j];
    }
    return 0;
}
