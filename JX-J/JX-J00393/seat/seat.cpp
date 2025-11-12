#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int wo=a[1];
    sort(a+1,a+1+n*m);
    int pl=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==wo){
            pl=n*m-i+1;
            break;
        }
    }
    int l=pl/n;
    if(pl%n){
        l++;
    }
    int h=0;
    if(l%2){
        h=(pl-1)%n+1;
    }
    else{
        h=n-((pl-1)%n);
    }
    cout<<l<<" "<<h;
    return 0;
}
