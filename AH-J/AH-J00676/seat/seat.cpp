#include <bits/stdc++.h>
using namespace std;

int n,m,pur,zt=0;
int a[200],s[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int k;cin>>k;
        if(i==1)pur=k;
        a[k]++;
    }
    int js=0;
    for(int i=101;i>=pur;i--){
        if(a[i]>0)js++;
    }
    int x,y;
    x=js/n+1;
    if(js%n==0)x--;
    if(x&1){
        y=js%n;
        if(js%n==0)y=n;
    }else{
        y=n-js%n+1;
        if(js%n==0)y=1;
    }
    cout<<x<<' '<<y;
    return 0;
}
