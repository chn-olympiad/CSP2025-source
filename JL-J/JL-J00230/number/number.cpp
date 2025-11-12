#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int x=1,b[1000001],k;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'&&a[i]>='0'){
            b[x]=a[i]-'0';
            x++;
        }
    }
    for(int i=1;i<x-1;i++){
        for(int j=i;j<x-1;j++){
            if(b[j]<b[j+1]){
                k=b[j];
                b[j]=b[j+1];
                b[j+1]=k;
            }
        }
    }
     for(int i=1;i<x;i++){
        cout<<b[i];
    }
    return 0;
}
