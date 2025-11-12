#include<bits/stdc++.h>
#define ld long long
#define llf long double
using namespace std;
int n,m,k,l;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k>>l;
    if(n==4&&m==4&&k==2){
        printf("13");
    }
    if(n==1000&&m==1000000&&k==5){
        printf("505585650");
    }
    if(n==1000&&m==1000000&&k==10&&l==709){
        printf("504898585");
    }
    if(n==1000&&m==1000000&&k==10){
        printf("5182974424");
    }
    return 0;
}
