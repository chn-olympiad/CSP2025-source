#include <bits/stdc++.h>
using namespace std;
long long n,fi,se=1,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=0,k;i<n*m;i++){
        cin>>k;
        if(i==0){
            fi=k;
        }
        else{
            if(k>fi){
                se++;
            }
        }
    }
    cout<<(se-1)/n+1<<' ';
    if((se-1)/n%2==0){
        cout<<(se-1)%n+1;
    }
    if((se-1)/n%2==1){
        cout<<n-(se-1)%n;
    }
    return 0;
}
