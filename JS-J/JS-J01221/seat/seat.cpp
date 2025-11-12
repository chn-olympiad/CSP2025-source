#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],p,q,b;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    p=a[1];
    for(int i=2;i<=n*m;i++)cin>>a[i];
    sort(a+1,a+1+n*m,cmp);
    while(a[++b]!=p);
    p=(b+n-1)/n;
    q=p%2==1?b-n*(p-1):n*p-b+1;
    cout<<p<<" "<<q;
    return 0;
}
