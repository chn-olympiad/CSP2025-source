#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string n,m;
    getline(cin,n);
    for(int i=1;i<=n.size();i++){
        if(n[i-1]>=48&&n[i-1]<58){
            m[i-1]=n[i-1];
    }
    }
    for(int z=1;z<=m.size()-1;z++){
    for(int j=1;j<=m.size();j++){
        if(m[j-1]<m[j]){
            int a=m[j-1];
            int m[j-1]=m[j];
            int m[j]=a;
    }
    }
    }
    cout<<m;
    return 0;
}
