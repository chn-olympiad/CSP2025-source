#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int s=a.length();
    int n=0;
    for(int i=0;i<s;i++){
        if(0<=int(a[i])-48 && int(a[i])-48<=9){
            n++;
        }
    }
    int j[n]={0},k=0;
    for(int i=0;i<s;i++){
        if(0<=int(a[i])-48 && int(a[i])-48<=9){
            j[k]=int(a[i])-48;
            k++;
        }
    }
    sort(j,j+n);
    for(int i=n-1;i>=0;i--){
        cout<<j[i];
    }
    return 0;
}
