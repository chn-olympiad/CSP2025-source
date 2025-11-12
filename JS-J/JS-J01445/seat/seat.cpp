#include<bits/stdc++.h>
using namespace std;
bool cmp(int pre,int nxt){
    return pre>nxt;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int m,n,a[105],mc;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m*n;i++){
        if(a[i]==r) mc=i;
    }
    int h,l;
    if(mc%n) l=mc/n+1;
    else l=mc/n;
    if(l%2) h=mc%(2*m);
    else h=m-mc%m+1;
    cout<<l<<" "<<h;
    return 0;
}
