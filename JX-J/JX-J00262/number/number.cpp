#include<bits/stdc++.h>
using namespace std;
string x;
long long a[10000000],b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    for(int i=0;i<x.size();i++){
        if(x[i]>='0'&&x[i]<='9'){
            a[b]=x[i]-'0';
            b++;
        }
    }sort(a,a+b);
    for(int i=b-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}


