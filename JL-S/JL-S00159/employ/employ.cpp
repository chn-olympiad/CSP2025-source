#include<iostream>
using namespace std;
int c[1000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=100&&m<=n){
        n=n*(n-1);
        cout<<n;
    }
    else if(n<=500&&m<=n){
        n=n*(n-1);
        cout<<n;
    }
    return 0;
}
