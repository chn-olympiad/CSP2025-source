#include<bits/stdc++.h
using namespace std;
int a[100005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m*n;i++)cin>>a[i];
    int ming=a[0],posk;
    sort(a,a+m*n);
    for(int i=m*n-1;i>=0;i++)
        if(ming==a[i])posk=n*m-i;
    int ansi=(posk+n-1)/n;
    int res=posk%(2*n);
    int ansj;
    if(res==0)ansj=1;
    else{
        if(res<=n)ansj=res;
        else ansj=2*n-res+1;
    }
    cout<<ansi<<' '<<ansj;
    return 0;
}
