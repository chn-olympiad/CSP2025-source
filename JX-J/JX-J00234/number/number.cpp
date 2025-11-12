#include<bits/stdc++.h>
using namespace std;
string a;
int n[100000],x;
int main(){
    freopen(number.in,'r',in);
    freopen(number.out,'w',out);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'||a[i]>='0'){
            n[x]=a[i]-48;
            x++;
        }
    }
    sort(n,n+x);
    for(int i=0;i<x;i++){
        cout<<n[i];
    }
    return 0;
}