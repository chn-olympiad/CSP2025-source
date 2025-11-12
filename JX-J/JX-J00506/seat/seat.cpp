#include <bits/stdc++.h>
using namespace std;
int n[101],d=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c=1;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>n[i];
    }
    int f=n[1];
    for(int i=2;i<=a*b;i++){
        if(f<n[i]) c++;
    }
    while(c>b){
        c-=b;
        d++;
    }
    if(d%2) cout<<d<<' '<<c;
    else cout<<d<<' '<<b-c+1;
    return 0;
}
