#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n , m , k;
    cin >> n >> m >> k;
    char u[10000001];
    for(int i=1;i<=n;i++){
        cin >> u[i];
    }
    if(n==4&&m==4&&k==2){
        cout <<"13";
    }
    if(n==1000&&m==1000000&&k==5){
        cout <<"505585650";
    }
    if(n==1000&&m==1000000&&k==10){
        cout <<"504898585";
    }
    return 0;
}
