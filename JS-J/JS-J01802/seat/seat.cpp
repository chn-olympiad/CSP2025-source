#include<bits/stdc++.h>
using namespace std;
int m,n,a,b,c=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    cin>>a;
    for(int i=2;i<=m*n;i++){
        cin>>b;
        if(a<b)c++;
    }
    if(c%n==0){
        if((c/n)%2==1)cout<<c/n<<' '<<n;
        if((c/n)%2==0)cout<<c/n<<' '<<1;
        return 0;
    }
    if((c/n)%2==1)cout<<c/n+1<<' '<<n-c%n+1;
    if((c/n)%2==0)cout<<c/n+1<<' '<<c%n;
    return 0;
}
/*
g++ seat.cpp -o seat -O2 -std=c++14

3 3
94 95 96 97 98 99 100 93 92

*/
