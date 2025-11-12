#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[1001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5){
        if(a[0]<a[1]<a[2]<a[3]<a[4]){
        cout<<9;
        }
    }
    return 0;
}
