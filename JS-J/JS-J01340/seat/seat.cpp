#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3+10;

int n,m;
int a[MAXN],R_sc,R_rk;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R_sc=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==R_sc){
            R_rk=n*m-i+1;
            break;
        }
    }
    int c=R_rk/n+1,r=R_rk%n;
    if(r==0){
        c--,r=n;
    }
    if(c%2==0){
        r=n-r+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
