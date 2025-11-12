#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,d=0,e;
    cin>>a>>b;
    int c[a+1]={0};
    for(int i=0;i<a;i++){
        cin>>c[i];
    }for(int i=0;i<a;i++){
        if(c[i]==b)d++;
    }cout<<d;
    return 0;

}
