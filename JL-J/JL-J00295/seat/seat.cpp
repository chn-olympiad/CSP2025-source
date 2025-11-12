#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,t;
    cin>>n>>m;
    long long csp[n*m];
    for(long long i=0;i<n*m;i++){
        cin>>csp[i];
    }
    long long id=1;
    for(long long i=1;i<n*m;i++){
        if(csp[i]>csp[0]){
            id++;
        }
    }
    long long c,v;
    if(id%n==0){
        if(id<=n)
            c=1;
        else
            c=id/n;
    }else
        c=c=id/n+1;
    if(c%2==1){
        v=id-n*(c-1);
    }else{
        v=n-(id-n*(c-1))+1;
    }
    cout<<c<<' '<<v;
    return 0;
}
