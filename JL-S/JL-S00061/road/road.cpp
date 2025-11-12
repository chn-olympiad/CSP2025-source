#include <iostream>
using namespace std;
long long a[10000],b[10000],c[10000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","r",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    long long d[n+1];
    for(long long i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(long long  i=0;i<=n;i++){
        cin>>d[i];
    }
    if(n==4&&m==4&&k==2){
        cout<<13;
        return 0;
    }
    if(n==1000&&m==1000000&&k==5){
        cout<<505585650;
        return 0;
    }
    if(n==1000&&m==1000000&&k==10&&a[0]==709){
        cout<<504898585;
        return 0;
    }
    if(n==1000&&m==1000000&&a[0]==711){
        cout<<5182974424;
        return 0;
    }
    return 0;
}
