#include<bits/stdc++.h>
using namespace std;
int f[150];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c=1,d,e;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>f[i];
    }
    for(int i=2;i<=a*b;i++){
        if(f[i]>f[1])c++;
    }
    d=(c-1)/a+1;
    e=(c-1)%a+1;
    if(d%2==1){
        cout<<d<<" "<<e;
        return 0;}
    cout<<d<<" "<<a+1-e;
    return 0;
}
