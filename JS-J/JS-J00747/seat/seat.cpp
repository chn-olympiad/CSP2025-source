#include<bits/stdc++.h>
using namespace std;
int a[1005],scr,n,m,c,r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    scr=a[1];
    sort(a+1,a+n*m+1);
    int pos=lower_bound(a+1,a+n*m+1,scr)-a;
    pos=n*m-pos+1;
    c=(pos-1)/n+1;
    r=pos%n;
    if(r==0) r=n;
    if(c%2==0) r=n+1-r;
    cout<<c<<' '<<r<<endl;
    return 0;
}
