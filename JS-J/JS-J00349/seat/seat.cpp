
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[200];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.out","w",stdout);
    freopen("seat.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    sort(a+2,a+n*m+1,cmp);
    for(int i=1;i<n*m;i++){
        if(a[i]<a[i+1])swap(a[i],a[i+1]);
        else {
            k=i;
            break;
        }
    }
    int y=k/n,t=k%n;
    if(t==0){

        cout<<y<<' ';
        if(y%2)cout<<n;
        else cout<<1;
    }else{
        y++;
        cout<<y<<' ';
        if(y%2)cout<<t;
        else cout<<n+1-t;
    }
    return 0;;
}
/*
I love luogu

CCF
CSP
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
*/
