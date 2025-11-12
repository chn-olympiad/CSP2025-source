#include<bits/stdc++.h>
#include<istream>
using namespace std;
int l[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        operator>>l[i] ;
    }
}
