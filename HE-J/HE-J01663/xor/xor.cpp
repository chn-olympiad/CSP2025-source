#include<bits/stdc++.h>
using namespace std;
int er(int a){
    int s[100], w=0,x=0;
    while(a!=0){
        w+=1;
        s[w]=a%2;
        a/=2;
    }
    for(int i=w;i>=1;i--){
        x=x*10+s[i];
    }
    return x;
}
int main(){
    int b,c;
    cin>>b>>c;
    int a[b+1];
    int d[b+1];
    for(int i=1;i<=b;i++){
        cin>>a[i];
        d[i]=er(a[i]);
    }
    for(int i=1;i<=b;i++){
        cout<<d[i]<<endl;
    }
    freopen("xor.in","r",stdin);
    return 0;
}
