#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],p,pos,x,y;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    p=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p) pos=i;
       // cout<<a[i]<<' ';
    }
    y=(pos-1)/n+1;
    if(pos%(2*n)==0) x=1;
    else if(pos%(2*n)<=n) x=pos%(2*n);
    else x=2*n-(pos%(2*n))+1;
    cout<<y<<' '<<x;
    return 0;
}