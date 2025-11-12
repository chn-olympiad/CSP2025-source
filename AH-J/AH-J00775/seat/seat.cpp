#include<bits/stdc++.h>
using namespace std;
long long n,m,a[109],k,pos;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)cin>>a[i];
    k=a[1];
    long long x=1,y=1;
    sort(a+1,a+1+n*m,cmp);
    for(long long i=1;i<=n*m;i++){
        if(a[i]==k)pos=i;
    }
    for(long long i=1;i<pos;i++){
        if(y%2==1)x++;
        else x--;
        if(x==n+1){
            x=n;
            y++;
        }
        if(x==0){
            x=1;
            y++;
        }
    }
    cout<<y<<' '<<x;
    return 0;
}
